#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include "ui_SearchDialog.h"  // Include the generated UI header file directly

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr);
    ~SearchDialog();

    QString getSearchText() const;

private:
    Ui::SearchDialog *ui;
};

#endif // SEARCHDIALOG_H
