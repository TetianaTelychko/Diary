#ifndef NEWCATEGORYWINDOW_H
#define NEWCATEGORYWINDOW_H

#include <QDialog>
#include <QtWidgets>
#include "imagemanager.h"
#include "constants.h"
#include "newcategorycontroller.h"
#include "datamodel.h"
class NewCategoryController;


class NewCategoryWindow : public QDialog
{
    Q_OBJECT
public:
    NewCategoryWindow(DataModel &dm);
    ~NewCategoryWindow();

    QLineEdit& getLineEdit_categoryName() const;

    QButtonGroup& getButtonGroup_checkBoxes() const;

private:
    NewCategoryController *controller;

    QLabel *label_categoryName;
    QLineEdit *lineEdit_categoryName;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    QMap<int, QCheckBox*> map_checkBoxes;
    QHBoxLayout *horizontalLayout_checkBoxes;
    QButtonGroup *buttonGroup_checkBoxes;

    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout2;
    QVBoxLayout *verticalLayout;

    void setupWindow();
    void setupWidgets();
    void setupCheckBoxes();
    void setupLayout();

private slots:
    void pushButton_ok_clicked();
    void pushButton_cancel_clicked();
};


#endif
