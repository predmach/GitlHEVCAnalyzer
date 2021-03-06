#include "busydialog.h"
#include "ui_busydialog.h"


BusyDialog::BusyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BusyDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint|Qt::WindowTitleHint);
    this->setFixedSize(this->size());
    setModualName("busy_dialog");
}

BusyDialog::~BusyDialog()
{
    delete ui;
}

void BusyDialog::setHintText(QString& str)
{
    this->ui->busyDynamicText->setText(str);
}


void BusyDialog::onUIUpdate(GitlUpdateUIEvt &rcEvt)
{
    if( rcEvt.hasParameter("busy_dialog_visible") )
    {
        /// show or hide this dialog
        this->setVisible(rcEvt.getParameter("busy_dialog_visible").toBool());
    }
    else if( rcEvt.hasParameter("decoding_progress") )
    {
        /// update info
        QVariant cVariant = rcEvt.getParameter("decoding_progress");
        this->ui->busyDynamicText->setText(cVariant.toString());
    }

}
