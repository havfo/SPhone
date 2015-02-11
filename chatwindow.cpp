#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent) : QDialog(parent), ui(new Ui::ChatWindow) {
    ui->setupUi(this);

    this->ui->chatInput->setFocusPolicy(Qt::StrongFocus);
    this->ui->chattedText->setFocusPolicy(Qt::NoFocus);
    this->ui->chattedText->setReadOnly(true);
}

ChatWindow::~ChatWindow() {
    delete ui;
}

void ChatWindow::appendMessage(const QString &message) {
     if (message.isEmpty()) {
         return;
     }

     QTextCursor cursor(this->ui->chattedText->textCursor());
     cursor.movePosition(QTextCursor::End);
     QTextTable *table = cursor.insertTable(1, 2, tableFormat);
     table->cellAt(0, 0).firstCursorPosition().insertText(" < " + buddy->getDisplayName() + " > ");
     table->cellAt(0, 1).firstCursorPosition().insertText(message);
     QScrollBar *bar = this->ui->chattedText->verticalScrollBar();
     bar->setValue(bar->maximum());
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

void ChatWindow::on_chatInput_returnPressed() {
    QString text = this->ui->chatInput->text();
    if (text.isEmpty()) {
        return;
    }

    // Send message here

    appendMessage(text);

    this->ui->chatInput->clear();
}
