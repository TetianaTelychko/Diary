#include "notewidget.h"

NoteWidget::NoteWidget(Note &note)
{
    if(note.isValid()){
        setupWidgets(note);
    }
    else{
        qDebug() << "The note object is not valid. (notewidget.cpp)";
    }
}

NoteWidget::~NoteWidget(){}

QPushButton& NoteWidget::getPushButton_link()
{
    return *pushButton_link;
}

int NoteWidget::getId()
{
    return id;
}

void NoteWidget::setupWidgets(Note &note)
{
    int widgetWidth = 205;
    int widgetHeight = 113;
    setMinimumSize(widgetWidth, widgetHeight);

    label_icon = new QLabel(this);
    icon = ImageManager::getFolder(note.getCategory().getColor());
    label_icon->setPixmap(icon.pixmap(22, 22));
    label_icon->setGeometry(10, 10, 22, 22);

    label_name = new QLabel(note.getName(), this);
    label_name->setGeometry(50, 10, widgetWidth - 60, 20);

    label_text = new QLabel(this);
    label_text->setGeometry(10, 50, widgetWidth - 20, widgetHeight - 60);
    QString newText = editText(note.getText());
    label_text->setText(newText);
    label_text->setWordWrap(true);

    pushButton_link = new QPushButton(this);
    pushButton_link->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton_link->setStyleSheet("QPushButton { background: transparent; } QPushButton:hover { background-color: rgba(255, 204, 0, 0.2); }");
    pushButton_link->setGeometry(0, 0, widgetWidth, widgetHeight);

    id = note.getId();
}

QString NoteWidget::editText(QString text)
{
    if(text.size() > 70){
        text = text.left(70);
        text.append("...");
    }
    return text;
}
