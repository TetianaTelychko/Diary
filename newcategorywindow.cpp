#include "newcategorywindow.h"

NewCategoryWindow::NewCategoryWindow(DataModel &dm)
{
    setupWindow();
    setupWidgets();
    setupCheckBoxes();
    setupLayout();
    controller = new NewCategoryController(dm, *this);
    connect(pushButton_ok, SIGNAL(clicked()), this, SLOT(pushButton_ok_clicked()));
    connect(pushButton_cancel, SIGNAL(clicked()), this, SLOT(pushButton_cancel_clicked()));
}

NewCategoryWindow::~NewCategoryWindow()
{
    for(auto iter = map_checkBoxes.begin(); iter != map_checkBoxes.end(); ++iter){
        horizontalLayout_checkBoxes->removeWidget(iter.value());
        delete iter.value();
    }
    map_checkBoxes.clear();
    delete horizontalLayout_checkBoxes;
    delete controller;
}

QLineEdit& NewCategoryWindow::getLineEdit_categoryName() const
{
    return *lineEdit_categoryName;
}

QButtonGroup& NewCategoryWindow::getButtonGroup_checkBoxes() const
{
    return *buttonGroup_checkBoxes;
}

void NewCategoryWindow::setupWindow()
{
    setFixedSize(320, 200);
    setWindowTitle("New category");
}

void NewCategoryWindow::setupWidgets()
{
    label_categoryName = new QLabel("Category name");
    lineEdit_categoryName = new QLineEdit();
    lineEdit_categoryName->setMaxLength(20);
    pushButton_ok = new QPushButton("Ok");
    pushButton_cancel = new QPushButton("Cancel");
}

void NewCategoryWindow::setupCheckBoxes()
{
    horizontalLayout_checkBoxes = new QHBoxLayout();
    buttonGroup_checkBoxes = new QButtonGroup(this);

    for(int id = constants::minColorId; id <= constants::maxColorId; ++id){
        map_checkBoxes.insert(id, new QCheckBox);
    }

    for(auto iter = map_checkBoxes.begin(); iter != map_checkBoxes.end(); ++iter){
        if(iter.key() == constants::minColorId){
            iter.value()->setCheckState(Qt::Checked);
        }
        iter.value()->setIcon(ImageManager::getCircle(iter.key()));

        horizontalLayout_checkBoxes->addWidget(iter.value());
        buttonGroup_checkBoxes->addButton(iter.value(), iter.key());
    }
}

void NewCategoryWindow::setupLayout()
{
    horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(label_categoryName);
    horizontalLayout->addWidget(lineEdit_categoryName);
    horizontalLayout2 = new QHBoxLayout;
    horizontalLayout2->addWidget(pushButton_cancel);
    horizontalLayout2->addWidget(pushButton_ok);

    verticalLayout = new QVBoxLayout(this);
    verticalLayout->addLayout(horizontalLayout);
    verticalLayout->addLayout(horizontalLayout_checkBoxes);
    verticalLayout->addLayout(horizontalLayout2);
}

void NewCategoryWindow::pushButton_ok_clicked()
{
    if(controller->pushButton_ok_handle()){
        this->close();
    }
}

void NewCategoryWindow::pushButton_cancel_clicked()
{
    this->close();
}
