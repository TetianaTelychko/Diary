#include "newcategorycontroller.h"

NewCategoryController::NewCategoryController(DataModel &dm, NewCategoryWindow &view) : dm(dm), view(view)
{

}

NewCategoryController::~NewCategoryController(){}

bool NewCategoryController::pushButton_ok_handle()
{
    QString newCategoryName = view.getLineEdit_categoryName().text();
    if(!newCategoryName.isEmpty()){
        if(!dm.categoryExists(newCategoryName)){
            int colorId = view.getButtonGroup_checkBoxes().checkedId();
            Color color = static_cast<Color>(colorId);
            Category category(newCategoryName, color);
            dm.addNewCategory(category);
            return true;
        }
        else{
            qDebug() << "A category with the same name already exists. (newcategory_controller.cpp)";
        }
    }
    else{
        qDebug() << "The category name is missing. (newcategory_controller.cpp)";
    }
    return false;
}
