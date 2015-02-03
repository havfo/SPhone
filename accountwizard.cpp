#include "accountwizard.h"
#include "ui_accountwizard.h"

AccountWizard::AccountWizard(QWidget *parent) : QDialog(parent), ui(new Ui::AccountWizard) {
    ui->setupUi(this);
}

AccountWizard::~AccountWizard() {
    delete ui;
}

void AccountWizard::on_buttonBox_accepted() {
    this->setResult(QDialog::Accepted);
    this->close();
}

void AccountWizard::on_buttonBox_rejected() {
    this->setResult(QDialog::Rejected);
    this->close();
}
