#include "sortdialog.h"
#include "ui_sortdialog.h"



SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog)
{
    ui->setupUi(this);

    ui->secondaryGroupBox->hide();
    ui->tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);



}

void SortDialog::SetColumnRange(QChar first, QChar last)
{

    ui->primaryColumnCombo->clear();
    ui->secondaryCoumnCombo->clear();
    ui->teritiaryColumnCombo->clear();

    ui->secondaryCoumnCombo->addItem(tr("None"));
    ui->teritiaryColumnCombo->addItem(tr("None"));
    ui->primaryColumnCombo->setMinimumSize(ui->secondaryCoumnCombo->sizeHint());

    QChar ch = first;
    while(ch <= last)
    {
        ui->primaryColumnCombo->addItem(ch);
        ui->secondaryCoumnCombo->addItem(ch);
        ui->teritiaryColumnCombo->addItem(ch);
        ch = ch.unicode() + 1;
    }

}

SortDialog::~SortDialog()
{
    delete ui;
}
