#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>
#include <QDebug>
#include "constants.h"


class Category
{
public:
    Category(QString name, Color color, int id = -1);
    ~Category();

    QString getName() const;
    Color getColor() const;
    int getColorId() const;

    int getId() const;
    void setId(int newId);

private:
    int id;
    QString name;
    Color color;
};


#endif
