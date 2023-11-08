#include "datamodel.h"

DataModel::DataModel()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString databasePath = QCoreApplication::applicationDirPath() + "/Database/database.db";
    db.setDatabaseName(databasePath);

    if(!db.open()){
        qDebug() << "Error connecting to database! (data_model.cpp)" << db.lastError().databaseText();
    }
    else{
        qDebug() << "Connection to the Database was successful! (data_model.cpp)";
    }

    query = QSqlQuery(db);
    updateCategoriesVector();
}

DataModel::~DataModel()
{
    db.close();
}

QVector<Category>& DataModel::getAllCategories()
{
    return categories;
}

void DataModel::getNotes(QVector<Note*> &vector, int count, int skip)
{
    QString q = "SELECT * FROM notes LIMIT " + QString::number(count) + " OFFSET " + QString::number(skip);
    query.exec(q);
    while(query.next()){
        QString name = query.value(1).toString();
        QString text = query.value(2).toString();
        int categoryId = query.value(3).toInt();
        Category *category = getCategory(categoryId);
        if(category != nullptr){
            QDateTime dateTime = query.value(4).toDateTime();
            int id = query.value(0).toInt();
            vector.push_back(new Note(name, text, *category, dateTime, id));
        }
        else{
            qDebug() << "Category index error while creating Note. (data_model.cpp getNotes)";
            break;
        }
    }
}

bool DataModel::getNoteById(Note **note, int id)
{
    query.exec("SELECT * FROM notes");
    while(query.next()){
        int currentId = query.value(0).toInt();
        if(id == currentId){
            QString name = query.value(1).toString();
            QString text = query.value(2).toString();
            int categoryId = query.value(3).toInt();
            Category *category = getCategory(categoryId);
            if(category != nullptr){
                QDateTime dateTime = query.value(4).toDateTime();
                *note = new Note(name, text, *category, dateTime, id);
                return true;
            }
            else{
                qDebug() << "Category index error while creating Note. (data_model.cpp getNoteById)";
                break;
            }
        }
    }
    return false;
}

int DataModel::getCountOfNotes()
{
    query.exec("SELECT COUNT(*) FROM notes");
    query.next();
    int count = query.value(0).toInt();
    return count;
}

Category* DataModel::getCategoryByName(QString &categoryName)
{
    for(Category &c : categories){
        if(c.getName() == categoryName){
            return &c;
        }
    }
    return nullptr;
}

bool DataModel::categoryExists(QString &categoryName)
{
    for(Category &c : categories){
        if(c.getName() == categoryName){
            return true;
        }
    }
    return false;
}

bool DataModel::noteExists(int id)
{
    query.exec("SELECT * FROM notes");
    while(query.next()){
        int currentId = query.value(0).toInt();
        if(id == currentId){
            return true;
        }
    }
    return false;
}

int DataModel::getNoteIdByName(QString &name)
{
    query.exec("SELECT * FROM notes");
    while(query.next()){
        QString currentName = query.value(1).toString();
        if(currentName == name){
            int id = query.value(0).toInt();
            return id;
        }
    }
    return -1;
}

void DataModel::addNewCategory(Category &category)
{
    query.prepare("INSERT INTO categories (name, color) VALUES (:name, :color)");
    query.bindValue(":name", category.getName());
    query.bindValue(":color", category.getColorId());
    query.exec();
    updateCategoriesVector();
}

void DataModel::addNote(Note &note)
{
    if(!noteExists(note.getId())){
        query.prepare("INSERT INTO notes (name, text, categoryId, datetime) VALUES (:newName, :newText, :newCategoryId, :newDateTime)");
        query.bindValue(":newName", note.getName());
        query.bindValue(":newText", note.getText());
        query.bindValue(":newCategoryId", note.getCategory().getId());
        query.bindValue(":newDateTime", note.getDateTime());
        query.exec();
    }
}

void DataModel::changeNote(Note &note)
{
    if(noteExists(note.getId())){
        query.prepare("UPDATE notes SET name = :newName, text = :newText, categoryId = :newCategoryId, datetime = :newDateTime WHERE id = :id");
        query.bindValue(":newName", note.getName());
        query.bindValue(":newText", note.getText());
        query.bindValue(":newCategoryId", note.getCategory().getId());
        query.bindValue(":newDateTime", note.getDateTime());
        query.bindValue(":id", note.getId());
        query.exec();
    }
}

void DataModel::updateCategoriesVector()
{
    query.exec("SELECT COUNT(*) FROM categories");
    query.next();
    numOfCategories = query.value(0).toInt();
    categories.clear();
    categories.reserve(numOfCategories);
    query.exec("SELECT * FROM categories");
    while(query.next()){
        Color color = static_cast<Color>(query.value(2).toInt());
        Category category(query.value(1).toString(), color, query.value(0).toInt());
        categories.append(category);
    }
}

Category* DataModel::getCategory(int id)
{
    for(int i = 0; i < categories.size(); ++i){
        if(categories[i].getId() == id){
            return &categories[i];
        }
    }
    return nullptr;
}

