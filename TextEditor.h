#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include "SearchDialog.h" // Include SearchDialog header

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr);
    ~TextEditor();

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void undoText();
    void redoText();
    void cutText();
    void copyText();
    void pasteText();
    void searchText();

private:
    Ui::TextEditor *ui;
    QString currentFile;
    QTextEdit *textEdit;
    SearchDialog *searchDialog; // Declare searchDialog here
};

#endif // TEXTEDITOR_H
