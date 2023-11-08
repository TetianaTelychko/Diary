#include "mainwindowcontroller.h"

MainWindowController::MainWindowController(DataModel &dm, MainWindow &view) : dm(dm), view(view)
{
    initializeView();
}

MainWindowController::~MainWindowController()
{
    clearVector();
}

void MainWindowController::pushButton_newCategory_handle()
{
    NewCategoryWindow ncw(dm);
    ncw.exec();
    updateCategories();
}

void MainWindowController::pushButton_newNote_handle(int noteId)
{
    NoteWindow nw(dm, noteId);
    nw.exec();
    updateNotes();
}

void MainWindowController::pushButton_navigationButton_handle(bool next)
{
    int page = view.getScrollableArea().getCurrentPage();
    page = (next) ? (page + 1) : (page - 1);
    if(pageExists(page)){
        view.getScrollableArea().changePage(page);
        int skip = (page - 1) * view.getScrollableArea().getNumberOfElementsOnPage();
        updateNotes(skip);
    }
}

void MainWindowController::initializeView()
{
    updateCategories();
    updateNotes();
}

void MainWindowController::updateCategories()
{
    QVector<Category>& categories = dm.getAllCategories();

    QListWidget &listWidget = view.getListWidget_categories();
    listWidget.clear();

    foreach(Category c, categories){
        QIcon icon = ImageManager::getCircle(c.getColor());
        QListWidgetItem *item = new QListWidgetItem(icon, c.getName());
        listWidget.addItem(item);
    }
}

void MainWindowController::updateNotes(int skip)
{
    ScrollableArea &sa = view.getScrollableArea();

    int count = sa.getNumberOfElementsOnPage();
    QVector<Note*> noteVector;
    dm.getNotes(noteVector, count, skip);

    sa.removeWidgetsFromLayout(noteWidgetVector);
    clearVector();

    for(int i = 0; i < noteVector.size(); ++i){
        noteWidgetVector.push_back(new NoteWidget(*noteVector[i]));
        delete noteVector[i];
    }
    noteVector.clear();

    sa.addWidgetsToLayout(noteWidgetVector);
    setupButtonsInWidgets();
    setupNavigationButtons();
}

void MainWindowController::clearVector()
{
    if(!noteWidgetVector.isEmpty()){
        for(int i = 0; i < noteWidgetVector.size(); ++i){
            delete noteWidgetVector[i];
        }
        noteWidgetVector.clear();
    }
}

void MainWindowController::setupButtonsInWidgets()
{
    for(int i = 0; i < noteWidgetVector.size(); ++i){
        NoteWidget *nw = noteWidgetVector.at(i);
        int noteId = nw->getId();
        QPushButton& button = nw->getPushButton_link();
        connect(&button, &QPushButton::clicked, this, [this, noteId](){ pushButton_newNote_handle(noteId); });
    }
}

void MainWindowController::setupNavigationButtons()
{
    QPushButton& nextButton = view.getScrollableArea().getNextButton();
    connect(&nextButton, &QPushButton::clicked, this, [this](){ pushButton_navigationButton_handle(true); });

    QPushButton& prevButton = view.getScrollableArea().getPrevButton();
    connect(&prevButton, &QPushButton::clicked, this, [this](){ pushButton_navigationButton_handle(false); });
}

bool MainWindowController::pageExists(int pageNum)
{
    if(pageNum <= 0){
        return false;
    }
    int minNumOfElements = (pageNum - 1) * view.getScrollableArea().getNumberOfElementsOnPage();
    if(dm.getCountOfNotes() > minNumOfElements){
        return true;
    }
    else{
        return false;
    }
}
