#include "callwindow.h"
#include "ui_callwindow.h"

CallWindow::CallWindow(QWidget *parent) : QDialog(parent), ui(new Ui::CallWindow) {
    ui->setupUi(this);

    buddiesListModel = new SBuddyListModel(buddies);
    this->ui->buddyList->setModel(buddiesListModel);
}

CallWindow::~CallWindow() {
    delete ui;
}

void CallWindow::addBuddyToChat(SBuddy *buddy) {

}

void CallWindow::addBuddyToCall(SBuddy *buddy) {

}

// Selected buddy in buddies list
void CallWindow::on_buddyList_clicked(const QModelIndex &index) {

}
