#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "mainwindowcontroller.h"
#include <QVector>
#include "category.h"
#include "imagemanager.h"
#include "datamodel.h"
#include "scrollablearea.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindowController;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(DataModel &dm, QWidget *parent = nullptr);
    ~MainWindow();

    QListWidget& getListWidget_categories();
    ScrollableArea& getScrollableArea();

private:
    Ui::MainWindow *ui;

    QWidget *widget;

    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout2;
    QHBoxLayout *horizontalLayout3;

    QLabel *label_categories;
    QLabel *label_allNotes;
    QListWidget *listWidget_categories;
    ScrollableArea *scrollableArea;
    QPushButton *pushButton_newCategory;
    QPushButton *pushButton_newNote;


    MainWindowController *controller;

    void setupMainWindow();
    void initialization();
    void layoutCustomization();
};


#endif
