#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QtSql>
#include <QDebug>
#include "category.h"
#include "constants.h"
#include "imagemanager.h"
#include "note.h"


class DataModel
{
public:
    DataModel();
    ~DataModel();

    QVector<Category>& getAllCategories();
    Category* getCategoryByName(QString &categoryName);
    void getNotes(QVector<Note*> &vector, int count, int skip = 0);
    bool getNoteById(Note **note, int id);
    int getCountOfNotes();

    bool categoryExists(QString &categoryName);
    bool noteExists(int id);
    int getNoteIdByName(QString &name);

    void addNewCategory(Category &category);
    void addNote(Note &note);

    void changeNote(Note &note);

private:
    QSqlDatabase db;
    QSqlQuery query;
    int numOfCategories;
    QVector<Category> categories;

    void updateCategoriesVector();
    Category* getCategory(int id);
};


#endif
