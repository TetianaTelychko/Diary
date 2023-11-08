#include "scrollablearea.h"

ScrollableArea::ScrollableArea()
{
    setupArea();
    dataInitialization();
    setupWidgets();
    setupLayout();
}

ScrollableArea::~ScrollableArea(){}

int ScrollableArea::getCurrentPage() const
{
    return currentPage;
}

void ScrollableArea::changePage(int newPage)
{
    QString newTextForLabel = "Page ";
    newTextForLabel.append(QString::number(newPage));
    pageLabel->setText(newTextForLabel);

    currentPage = newPage;
}

int ScrollableArea::getNumberOfElementsOnPage() const
{
    return numberOfElementsOnPage;
}

void ScrollableArea::addWidgetsToLayout(QVector<NoteWidget *> &vector)
{
    int row = 0;
    int column = 0;

    for(int i = 0; i < vector.size(); ++i){
        gridLayout->addWidget(vector[i], row, column, Qt::AlignLeft | Qt::AlignTop);
        next(row, column);
    }
}

void ScrollableArea::removeWidgetsFromLayout(QVector<NoteWidget *> &vector)
{
    for(int i = 0; i < vector.size(); ++i){
        gridLayout->removeWidget(vector[i]);
    }
}

QPushButton& ScrollableArea::getNextButton() const
{
    return *nextButton;
}

QPushButton& ScrollableArea::getPrevButton() const
{
    return *prevButton;
}

void ScrollableArea::setupArea()
{
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Window, QColor("#FFFFFF"));
    this->setPalette(palette);
}

void ScrollableArea::dataInitialization()
{
    currentPage = 1;
    numberOfElementsOnPage = 10;
}

void ScrollableArea::setupWidgets()
{
    mainLayout = new QVBoxLayout();

    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);

    gridWidget = new QWidget(scrollArea);

    gridLayout = new QGridLayout(gridWidget);
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->setSpacing(0);

    bottomLayout = new QHBoxLayout();

    pageLabel = new QLabel("Page 1");
    pageLabel->setAlignment(Qt::AlignCenter);
    nextButton = new QPushButton("->");
    prevButton = new QPushButton("<-");
}

void ScrollableArea::setupLayout()
{
    bottomLayout->addWidget(prevButton);
    bottomLayout->addWidget(pageLabel);
    bottomLayout->addWidget(nextButton);

    mainLayout->addWidget(scrollArea);
    mainLayout->addLayout(bottomLayout);

    this->setLayout(mainLayout);
    scrollArea->setWidget(gridWidget);
}

void ScrollableArea::next(int &row, int &column)
{
    //2 elements per line
    if(column == 0){
        column = 1;
    }
    else{
        column = 0;
        ++row;
    }
}
