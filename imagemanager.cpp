#include "imagemanager.h"

ImageManager::ImageManager(){}

ImageManager::~ImageManager(){}

QIcon ImageManager::getCircle(int id)
{
    return getCircle(static_cast<Color>(id));
}

QIcon ImageManager::getFolder(int id)
{
    return getFolder(static_cast<Color>(id));
}

QIcon ImageManager::getOpenFolder(int id)
{
    return getOpenFolder(static_cast<Color>(id));
}

QIcon ImageManager::getCircle(Color color)
{
    switch(color){
    case Color::RED:
        return QIcon(":/new/prefix2/Images/folder circle color1.png");
    case Color::ORANGE:
        return QIcon(":/new/prefix2/Images/folder circle color2.png");
    case Color::YELLOW:
        return QIcon(":/new/prefix2/Images/folder circle color3.png");
    case Color::GREEN :
        return QIcon(":/new/prefix2/Images/folder circle color4.png");
    case Color::BLUE:
        return QIcon(":/new/prefix2/Images/folder circle color5.png");
    case Color::GREY:
        return QIcon(":/new/prefix2/Images/folder circle color6.png");
    }
}

QIcon ImageManager::getFolder(Color color)
{
    switch(color){
    case Color::RED:
        return QIcon(":/new/prefix2/Images/folder color1.png");
    case Color::ORANGE:
        return QIcon(":/new/prefix2/Images/folder color2.png");
    case Color::YELLOW:
        return QIcon(":/new/prefix2/Images/folder color3.png");
    case Color::GREEN:
        return QIcon(":/new/prefix2/Images/folder color4.png");
    case Color::BLUE:
        return QIcon(":/new/prefix2/Images/folder color5.png");
    case Color::GREY:
        return QIcon(":/new/prefix2/Images/folder color6.png");
    }
}

QIcon ImageManager::getOpenFolder(Color color)
{
    switch(color){
    case Color::RED:
        return QIcon(":/new/prefix2/Images/folder open color1.png");
    case Color::ORANGE:
        return QIcon(":/new/prefix2/Images/folder open color2.png");
    case Color::YELLOW:
        return QIcon(":/new/prefix2/Images/folder open color3.png");
    case Color::GREEN:
        return QIcon(":/new/prefix2/Images/folder open color4.png");
    case Color::BLUE:
        return QIcon(":/new/prefix2/Images/folder open color5.png");
    case Color::GREY:
        return QIcon(":/new/prefix2/Images/folder open color6.png");
    }
}
