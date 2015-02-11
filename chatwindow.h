#ifndef CALLWINDOW_H
#define CALLWINDOW_H

#include <QDialog>
#include <QList>
#include <QCloseEvent>
#include <QTextTable>
#include <QTextTableFormat>
#include <QTextCursor>
#include <QScrollBar>
#include <pjsua2.hpp>
#include "account.h"
#include "buddy.h"

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QDialog {
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = 0);
    ~ChatWindow();
    void incomingChatFromBuddy(SAccount *account, const OnInstantMessageParam &instantMessage);
    void outgoingChatToAddress(SAccount *account, QString *sipAddress);
    void incomingTypingIndication(SAccount *account, const OnTypingIndicationParam &typingIndication);
    void setAccount(SAccount *value);
    void setBuddy(SBuddy *value);

protected:
    virtual void closeEvent(QCloseEvent *event);

private:
    Ui::ChatWindow *ui;
    SAccount *account;
    SBuddy *buddy;
    QTextTableFormat tableFormat;
    void appendMessage(const QString &message);

private slots:
    void onInstantMessage(const OnInstantMessageParam &instantMessage);
    void onInstantMessageStatus(const OnInstantMessageStatusParam &instantMessageStatus);
    void onTypingIndication(const OnTypingIndicationParam &typingIndication);
    void on_chatInput_returnPressed();
};

#endif // CALLWINDOW_H
