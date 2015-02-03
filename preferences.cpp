#include "preferences.h"
#include "ui_preferences.h"

Preferences::Preferences(QWidget *parent) : QDialog(parent), ui(new Ui::Preferences) {
    ui->setupUi(this);
}

Preferences::~Preferences() {
    delete ui;
}

void Preferences::on_buttonBox_accepted() {
    this->setResult(QDialog::Accepted);
    this->close();
}

void Preferences::on_buttonBox_rejected() {
    this->setResult(QDialog::Rejected);
    this->close();
}

void Preferences::on_account_button_clicked() {
    if (ui->stackedWidget->currentIndex() != 0) {
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void Preferences::on_device_button_clicked() {
    if (ui->stackedWidget->currentIndex() != 1) {
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void Preferences::on_logging_button_clicked() {
    if (ui->stackedWidget->currentIndex() != 2) {
        ui->stackedWidget->setCurrentIndex(2);
    }
}

void Preferences::on_advanced_button_clicked() {
    if (ui->stackedWidget->currentIndex() != 3) {
        ui->stackedWidget->setCurrentIndex(3);
    }
}
