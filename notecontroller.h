#ifndef NOTECONTROLLER_H
#define NOTECONTROLLER_H

#include <QObject>
#include "notewindow.h"
#include "imagemanager.h"
#include "note.h"
class NoteWindow;


class NoteController : public QObject
{
    Q_OBJECT
public:
    NoteController(DataModel &dm, NoteWindow &view, int noteId = -1);
    ~NoteController();

public slots:
    void okPushButtonHandle();

private:
    DataModel &dm;
    NoteWindow &view;
    int noteId;

    void setupCategoryComboBox();
    void loadDataFromNote();
};


#endif
