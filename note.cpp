#include "note.h"

Note::Note(QString name, QString text, Category &category, QDateTime dateTime, int id)
    :name(name),
    text(text),
    category(category),
    dateTime(dateTime),
    id(id)
{
    /*If there is no given object in the database, then the identifier should be assigned the value -1 automatically*/
}

Note::~Note(){}

int Note::getId() const
{
    return id;
}

bool Note::isValid()
{
    return (id > 0);
}

QDateTime Note::getDateTime() const
{
    return dateTime;
}

QString Note::getName() const
{
    return name;
}

Category& Note::getCategory() const
{
    return category;
}

QString Note::getText() const
{
    return text;
}
