#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QVector>
#include "mainwindow.h"
#include "datamodel.h"
#include "newcategorywindow.h"
#include "notewidget.h"
#include "scrollablearea.h"
#include "notewindow.h"


class MainWindow;

class MainWindowController : public QObject
{
    Q_OBJECT
public:
    MainWindowController(DataModel &dm, MainWindow &view);
    ~MainWindowController();

public slots:
    void pushButton_newCategory_handle();
    void pushButton_newNote_handle(int noteId = -1);
    void pushButton_navigationButton_handle(bool next);

private:
    DataModel &dm;
    MainWindow &view;
    QVector<NoteWidget*> noteWidgetVector;

    void initializeView();
    void updateCategories();
    void updateNotes(int skip = 0);
    void clearVector();
    void setupButtonsInWidgets();
    void setupNavigationButtons();
    bool pageExists(int pageNum);
};


#endif
