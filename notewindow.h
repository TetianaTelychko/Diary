#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QDialog>
#include <QtWidgets>
#include "datamodel.h"
#include "notecontroller.h"
#include "note.h"
class NoteController;


class NoteWindow : public QDialog
{
    Q_OBJECT
public:
    NoteWindow(DataModel &dm, int noteId = -1);
    ~NoteWindow();

    QLineEdit& getNameLineEdit();
    QComboBox& getCategoryComboBox();
    QTextEdit& getNoteTextEdit();

public slots:
    void okPushButton_clicked();
    void cancelPushButton_clicked();

private:
    NoteController *controller;

    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout;
    QHBoxLayout *bottomLayout;

    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *categoryLabel;
    QComboBox *categoryComboBox;

    QTextEdit *noteTextEdit;

    QPushButton *cancelPushButton;
    QPushButton *okPushButton;

    void configureWindow();
    void setupWindow();
    void setupWidgets();
    void setupLayout();
};


#endif
