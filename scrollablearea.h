#ifndef SCROLLABLEAREA_H
#define SCROLLABLEAREA_H

#include <QWidget>
#include <QtWidgets>
#include <QPalette>
#include "notewidget.h"


class ScrollableArea : public QWidget
{
    Q_OBJECT
public:
    ScrollableArea();
    ~ScrollableArea();

    int getCurrentPage() const;
    void changePage(int newPage);
    int getNumberOfElementsOnPage() const;
    QPushButton& getNextButton() const;
    QPushButton& getPrevButton() const;

    void addWidgetsToLayout(QVector<NoteWidget*> &vector);
    void removeWidgetsFromLayout(QVector<NoteWidget*> &vector);

private:
    int currentPage;
    int numberOfElementsOnPage;

    QVBoxLayout *mainLayout;

    QScrollArea *scrollArea;
    QWidget *gridWidget;
    QGridLayout *gridLayout;

    QHBoxLayout *bottomLayout;
    QLabel *pageLabel;
    QPushButton *nextButton;
    QPushButton *prevButton;

    void setupArea();
    void dataInitialization();
    void setupWidgets();
    void setupLayout();
    void next(int &row, int &column);
};


#endif
