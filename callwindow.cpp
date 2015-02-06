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

void CallWindow::incomingCallFromBuddy(SBuddy *buddy, const OnIncomingCallParam &incomingCall) {

}

void CallWindow::incomingChatFromBuddy(SBuddy *buddy, const OnInstantMessageParam &instantMessage) {

}

void CallWindow::outgoingCallToBuddy(SBuddy *buddy) {

}

void CallWindow::outgoingChatToBuddy(SBuddy *buddy) {

}

void CallWindow::incomingTypingIndication(SBuddy *buddy, const OnTypingIndicationParam &typingIndication) {

}

// Selected buddy in buddies list
void CallWindow::on_buddyList_clicked(const QModelIndex &index) {

}
