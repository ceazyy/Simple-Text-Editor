#include "TextEditor.h"
#include "ui_TextEditor.h"
#include "SearchDialog.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QTextCursor>

TextEditor::TextEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    searchDialog = new SearchDialog(this);
    // connect every block of option with their action
    
    connect(ui->actionNew, &QAction::triggered, this, &TextEditor::newFile);
    connect(ui->actionOpen, &QAction::triggered, this, &TextEditor::openFile);
    connect(ui->actionSave, &QAction::triggered, this, &TextEditor::saveFile);
    connect(ui->actionSave_As, &QAction::triggered, this, &TextEditor::saveFileAs);
    connect(ui->actionUndo, &QAction::triggered, this, &TextEditor::undoText);
    connect(ui->actionRedo, &QAction::triggered, this, &TextEditor::redoText);
    connect(ui->actionCut, &QAction::triggered, this, &TextEditor::cutText);
    connect(ui->actionCopy, &QAction::triggered, this, &TextEditor::copyText);
    connect(ui->actionPaste, &QAction::triggered, this, &TextEditor::pasteText);
    connect(ui->actionSearch, &QAction::triggered, this, &TextEditor::searchText);
}

TextEditor::~TextEditor()
{
    delete ui;
    delete searchDialog;
}

void TextEditor::newFile()
{
    currentFile.clear();
    textEdit->setText(QString());
}

void TextEditor::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    textEdit->setText(text);
    file.close();
}

void TextEditor::saveFile()
{
    QString fileName;
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save as");
        currentFile = fileName;
    } else {
        fileName = currentFile;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = textEdit->toPlainText();
    out << text;
    file.close();
}

void TextEditor::saveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = textEdit->toPlainText();
    out << text;
    file.close();
}

void TextEditor::undoText()
{
    textEdit->undo();
}

void TextEditor::redoText()
{
    textEdit->redo();
}

void TextEditor::cutText()
{
    textEdit->cut();
}

void TextEditor::copyText()
{
    textEdit->copy();
}

void TextEditor::pasteText()
{
    textEdit->paste();
}
// I have a error here I want to fix, if anyone can help me i'd be glad
void TextEditor::searchText()
{
    // Show the search dialog and wait for user input
    if (searchDialog->exec() == QDialog::Accepted) {
        // Get the search text from the dialog
        QString searchText = searchDialog->getSearchText();

        // If search text is not empty, proceed with search
        if (!searchText.isEmpty()) {
            QTextDocument *document = textEdit->document();
            QTextCursor cursor(document);
            QTextCursor highlightCursor(document);

            // Clear any previous highlights
            cursor.setPosition(0);
            textEdit->setTextCursor(cursor);
            textEdit->setTextBackgroundColor(Qt::white);

            // Find and highlight all occurrences of the search text
            QTextCharFormat colorFormat;
            colorFormat.setBackground(Qt::yellow);
            while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
                highlightCursor = document->find(searchText, highlightCursor);
                if (!highlightCursor.isNull()) {
                    highlightCursor.mergeCharFormat(colorFormat);
                }
            }

            // Move cursor to the first occurrence of the search text
            cursor = textEdit->textCursor();
            cursor.movePosition(QTextCursor::Start);
            cursor = document->find(searchText, cursor);
            textEdit->setTextCursor(cursor);

            // Scroll to the position of the search block
            if (!cursor.isNull())
                textEdit->ensureCursorVisible();
        }
    }
}
