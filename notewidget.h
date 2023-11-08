#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "category.h"
#include "note.h"
#include "imagemanager.h"


class NoteWidget : public QWidget
{
    Q_OBJECT
public:
    NoteWidget(Note &note);
    ~NoteWidget();

    QPushButton& getPushButton_link();
    int getId();

signals:
private:
    QLabel *label_icon;
    QIcon icon;
    QLabel *label_name;
    QLabel *label_text;
    QPushButton *pushButton_link;
    int id;

    void setupWidgets(Note &note);
    QString editText(QString text);
};


#endif
