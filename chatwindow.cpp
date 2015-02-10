#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent) : QDialog(parent), ui(new Ui::ChatWindow) {
    ui->setupUi(this);
}

ChatWindow::~ChatWindow() {
    delete ui;
}

void ChatWindow::closeEvent(QCloseEvent *event) {
    this->buddy->setChatWindowOpen(false);
    event->accept();
}

void ChatWindow::setAccount(SAccount *value) {
    this->account = value;
}

void ChatWindow::setBuddy(SBuddy *value) {
    buddy = value;

    buddy->setChatWindowOpen(true);
}

void ChatWindow::onInstantMessage(const OnInstantMessageParam &instantMessage) {

}

void ChatWindow::onInstantMessageStatus(const OnInstantMessageStatusParam &instantMessageStatus) {

}

void ChatWindow::onTypingIndication(const OnTypingIndicationParam &typingIndication) {

}
