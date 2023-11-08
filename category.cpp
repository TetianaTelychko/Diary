#include "category.h"

Category::Category(QString name, Color color, int id) : name(name), color(color), id(id)
{
    /*If there is no given object in the database, then the identifier should be assigned the value -1 automatically*/
}

Category::~Category(){}

QString Category::getName() const
{
    return name;
}

Color Category::getColor() const
{
    return color;
}

int Category::getColorId() const
{
    return static_cast<int>(color);
}

int Category::getId() const
{
    return id;
}

void Category::setId(int newId)
{
    id = newId;
}
