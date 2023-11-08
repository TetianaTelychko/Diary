#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(DataModel &dm, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupMainWindow();
    initialization();
    layoutCustomization();

    controller = new MainWindowController(dm, *this);
    connect(pushButton_newCategory, SIGNAL(clicked()), controller, SLOT(pushButton_newCategory_handle()));
    connect(pushButton_newNote, SIGNAL(clicked()), controller, SLOT(pushButton_newNote_handle()));
}

MainWindow::~MainWindow()
{
    delete controller;
    delete scrollableArea;
    delete ui;
}

QListWidget& MainWindow::getListWidget_categories()
{
    return *listWidget_categories;
}

ScrollableArea& MainWindow::getScrollableArea()
{
    return *scrollableArea;
}

void MainWindow::setupMainWindow()
{
    setMinimumSize(640, 480);
    setWindowTitle("Diary");
}

void MainWindow::initialization()
{
    widget = new QWidget();

    mainLayout = new QVBoxLayout();
    horizontalLayout = new QHBoxLayout();
    horizontalLayout2 = new QHBoxLayout();
    horizontalLayout3 = new QHBoxLayout();

    label_categories = new QLabel("Categories");
    label_allNotes = new QLabel("All Notes");
    listWidget_categories = new QListWidget();
    scrollableArea = new ScrollableArea();
    pushButton_newCategory = new QPushButton("New Category");
    pushButton_newNote = new QPushButton("New Note");
}

void MainWindow::layoutCustomization()
{
    horizontalLayout->addWidget(label_categories);
    horizontalLayout->addWidget(label_allNotes);

    horizontalLayout2->addWidget(listWidget_categories);
    horizontalLayout2->addWidget(scrollableArea);
    horizontalLayout2->setStretchFactor(listWidget_categories, 1);
    horizontalLayout2->setStretchFactor(scrollableArea, 3);

    horizontalLayout3->addWidget(pushButton_newCategory);
    horizontalLayout3->addWidget(pushButton_newNote);

    mainLayout->addLayout(horizontalLayout);
    mainLayout->addLayout(horizontalLayout2);
    mainLayout->addLayout(horizontalLayout3);

    widget->setLayout(mainLayout);
    setCentralWidget(widget);
}

