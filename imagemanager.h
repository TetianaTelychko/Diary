#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <QIcon>
#include "constants.h"


class ImageManager
{
public:
    ImageManager();
    ~ImageManager();

    static QIcon getCircle(int id);
    static QIcon getFolder(int id);
    static QIcon getOpenFolder(int id);

    static QIcon getCircle(Color color);
    static QIcon getFolder(Color color);
    static QIcon getOpenFolder(Color color);
};


#endif
