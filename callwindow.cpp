#include "callwindow.h"
#include "ui_callwindow.h"

CallWindow::CallWindow(QWidget *parent) : QDialog(parent), ui(new Ui::CallWindow) {
    ui->setupUi(this);

    buddyListModel = new SBuddyListModel(buddies);
    this->ui->buddyList->setModel(buddyListModel);
}

CallWindow::~CallWindow() {
    delete ui;
}

void CallWindow::incomingCallFromBuddy(SAccount *account, const OnIncomingCallParam &incomingCall) {

}

void CallWindow::incomingChatFromBuddy(SAccount *account, const OnInstantMessageParam &instantMessage) {

}

void CallWindow::outgoingCallToAddress(SAccount *account, QString *sipAddress) {

}

void CallWindow::outgoingChatToBuddy(SAccount *account, QString *sipAddress) {

}

void CallWindow::incomingTypingIndication(SBuddy *buddy, const OnTypingIndicationParam &typingIndication) {

}

// Selected buddy in buddies list
void CallWindow::on_buddyList_clicked(const QModelIndex &index) {

}
