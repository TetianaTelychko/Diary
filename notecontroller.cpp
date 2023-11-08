#include "notecontroller.h"

NoteController::NoteController(DataModel &dm, NoteWindow &view, int noteId) : dm(dm), view(view), noteId(noteId)
{
    setupCategoryComboBox();
    if(noteId != -1){
        loadDataFromNote();
    }
}

NoteController::~NoteController()
{

}

void NoteController::okPushButtonHandle()
{
    QString categoryName = view.getCategoryComboBox().currentText();
    Category *category = dm.getCategoryByName(categoryName);
    QString name = view.getNameLineEdit().text();

    if(category != nullptr && !name.isEmpty()){
        QString text = view.getNoteTextEdit().toPlainText();
        QDateTime dateTime = QDateTime::currentDateTime();
        Note note(name, text, *category, dateTime, noteId);

        int existingNoteId = dm.getNoteIdByName(name);
        if(noteId == -1){
            if(existingNoteId == -1){
                dm.addNote(note);
            }
        }
        else{
            if(existingNoteId == -1 || existingNoteId == noteId){
                dm.changeNote(note);
            }
        }
    }
}

void NoteController::setupCategoryComboBox()
{
    QVector<Category> &categoryVector = dm.getAllCategories();
    QComboBox &categoryComboBox = view.getCategoryComboBox();

    for(Category &c : categoryVector){
        int index = c.getId();
        QIcon icon = ImageManager::getOpenFolder(c.getColor());
        QString name = c.getName();
        categoryComboBox.insertItem(index, icon, name);
    }
}

void NoteController::loadDataFromNote()
{
    Note *note = nullptr;
    if(dm.getNoteById(&note, noteId)){
        view.getNameLineEdit().setText(note->getName());
        view.getNoteTextEdit().setText(note->getText());
        view.getCategoryComboBox().setCurrentText(note->getCategory().getName());
        delete note;
    }
}















