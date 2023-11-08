#ifndef NOTE_H
#define NOTE_H

#include <QObject>
#include "category.h"
#include <QDateTime>


class Note : public QObject
{
    Q_OBJECT
public:
    Note(QString name, QString text, Category &category, QDateTime dateTime, int id = -1);
    ~Note();

    QString getName() const;
    QString getText() const;
    Category& getCategory() const;
    QDateTime getDateTime() const;

    int getId() const;
    bool isValid();

private:
    int id;
    QString name;
    QString text;
    Category &category;
    QDateTime dateTime;
};


#endif
