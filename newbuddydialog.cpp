#include "newbuddydialog.h"
#include "ui_newbuddydialog.h"

NewBuddyDialog::NewBuddyDialog(QWidget *parent) : QDialog(parent), ui(new Ui::NewBuddyDialog) {
    ui->setupUi(this);
}

NewBuddyDialog::~NewBuddyDialog() {
    delete ui;
}

bool NewBuddyDialog::getSubsribeToPresence() const {
    return subsribeToPresence;
}


QString NewBuddyDialog::getSipAddress() const {
    return sipAddress;
}

QString NewBuddyDialog::getDisplayName() const {
    return displayName;
}

void NewBuddyDialog::on_buttonBox_accepted() {
    sipAddress = this->ui->buddySipAddress->text();
    displayName = this->ui->buddyDisplayName->text();
    subsribeToPresence = this->ui->subscribeToPresence->checkState();

    QString sipAddressRegExp = "\\bsip:[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}\\b";
    QRegExp rx(sipAddressRegExp);

    if (rx.exactMatch(sipAddress)) {
        this->setResult(QDialog::Accepted);
        this->close();
    } else if (rx.exactMatch("sip:" + sipAddress)) {
        sipAddress = "sip:" + sipAddress;
        this->setResult(QDialog::Accepted);
        this->close();
    } else {
        QMessageBox ret;
        ret.setText("Invalid SIP Address");
        ret.exec();
    }
}

void NewBuddyDialog::on_buttonBox_rejected() {
    this->setResult(QDialog::Rejected);
    this->close();
}
