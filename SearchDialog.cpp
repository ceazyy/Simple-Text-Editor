#include "SearchDialog.h"
#include "ui_SearchDialog.h"

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);

    // Connect signals and slots for OK and Cancel buttons
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SearchDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &SearchDialog::reject);
}
// destructor
SearchDialog::~SearchDialog()
{
    delete ui;
}

QString SearchDialog::getSearchText() const
{
    return ui->lineEdit->text();
}
