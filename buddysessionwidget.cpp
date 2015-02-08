#include "buddysessionwidget.h"
#include "ui_buddysessionwidget.h"

BuddySessionWidget::BuddySessionWidget(QWidget *parent) : QWidget(parent), ui(new Ui::BuddySessionWidget) {
    ui->setupUi(this);

    this->ui->chatInput->setFocusPolicy(Qt::StrongFocus);
    this->ui->chattedText->setFocusPolicy(Qt::NoFocus);
    this->ui->chattedText->setReadOnly(true);
}

BuddySessionWidget::~BuddySessionWidget() {
    delete ui;
}

void BuddySessionWidget::appendMessage(const QString &message) {
     if (message.isEmpty()) {
         return;
     }

     QTextCursor cursor(this->ui->chattedText->textCursor());
     cursor.movePosition(QTextCursor::End);
     QTextTable *table = cursor.insertTable(1, 2, tableFormat);
     table->cellAt(0, 0).firstCursorPosition().insertText(" < " + account->getDisplayName() + " > ");
     table->cellAt(0, 1).firstCursorPosition().insertText(message);
     QScrollBar *bar = this->ui->chattedText->verticalScrollBar();
     bar->setValue(bar->maximum());
}

void BuddySessionWidget::setAccount(SAccount *account) {
    this->account = account;
}

void BuddySessionWidget::setBuddy(SBuddy *buddy) {
    this->buddy = buddy;
}


// Switch to chat view
void BuddySessionWidget::on_chatButton_clicked() {
    if (ui->stackedWidget->currentIndex() != 0) {
        ui->stackedWidget->setCurrentIndex(0);
    }
}

// Switch to call view
void BuddySessionWidget::on_callButton_clicked() {
    if (ui->stackedWidget->currentIndex() != 1) {
        ui->stackedWidget->setCurrentIndex(1);
    }
}

// Switch to video call view
void BuddySessionWidget::on_videoCallButton_clicked() {
    if (ui->stackedWidget->currentIndex() != 2) {
        ui->stackedWidget->setCurrentIndex(2);
    }
}

// Switch to screen share view
void BuddySessionWidget::on_screenShareButton_clicked() {
    if (ui->stackedWidget->currentIndex() != 3) {
        ui->stackedWidget->setCurrentIndex(3);
    }
}

// Return pressed in chat input, send chat message
void BuddySessionWidget::on_chatInput_returnPressed() {
    QString text = this->ui->chatInput->text();
    if (text.isEmpty()) {
        return;
    }

    // Send message here

    appendMessage(text);

    this->ui->chatInput->clear();
}
