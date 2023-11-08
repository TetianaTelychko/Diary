#include "notewindow.h"

NoteWindow::NoteWindow(DataModel &dm, int noteId)
{
    configureWindow();
    controller = new NoteController(dm, *this, noteId);
    connect(okPushButton, SIGNAL(clicked()), this, SLOT(okPushButton_clicked()));
    connect(cancelPushButton, SIGNAL(clicked()), this, SLOT(cancelPushButton_clicked()));
}

NoteWindow::~NoteWindow()
{
    delete controller;
}

QLineEdit& NoteWindow::getNameLineEdit()
{
    return *nameLineEdit;
}

QComboBox& NoteWindow::getCategoryComboBox()
{
    return *categoryComboBox;
}

QTextEdit& NoteWindow::getNoteTextEdit()
{
    return *noteTextEdit;
}

void NoteWindow::okPushButton_clicked()
{
    controller->okPushButtonHandle();
    this->close();
}

void NoteWindow::cancelPushButton_clicked()
{
    this->close();
}

void NoteWindow::configureWindow()
{
    setupWindow();
    setupWidgets();
    setupLayout();
}

void NoteWindow::setupWindow()
{
    setFixedSize(640, 480);
    setWindowTitle("New note");
}

void NoteWindow::setupWidgets()
{
    nameLabel = new QLabel("Name");
    nameLineEdit = new QLineEdit();
    categoryLabel = new QLabel("Category");
    categoryComboBox = new QComboBox();

    noteTextEdit = new QTextEdit();

    cancelPushButton = new QPushButton("Cancel");
    okPushButton = new QPushButton("Ok");
}

void NoteWindow::setupLayout()
{
    topLayout = new QHBoxLayout();
    topLayout->addWidget(nameLabel);
    topLayout->addWidget(nameLineEdit);
    topLayout->addWidget(categoryLabel);
    topLayout->addWidget(categoryComboBox);

    bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(cancelPushButton);
    bottomLayout->addWidget(okPushButton);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(noteTextEdit);
    mainLayout->addLayout(bottomLayout);
}
