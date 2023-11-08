#ifndef NEWCATEGORYCONTROLLER_H
#define NEWCATEGORYCONTROLLER_H

#include "newcategorywindow.h"
#include "datamodel.h"
#include "constants.h"
class NewCategoryWindow;


class NewCategoryController : public QObject
{
    Q_OBJECT
public:
    NewCategoryController(DataModel &dm, NewCategoryWindow &view);
    ~NewCategoryController();

public slots:
    bool pushButton_ok_handle();

private:
    DataModel &dm;
    NewCategoryWindow &view;
};


#endif
