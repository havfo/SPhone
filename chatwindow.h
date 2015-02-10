#ifndef CALLWINDOW_H
#define CALLWINDOW_H

#include <QDialog>
#include <QList>
#include <QCloseEvent>
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

private slots:
    void onInstantMessage(const OnInstantMessageParam &instantMessage);
    void onInstantMessageStatus(const OnInstantMessageStatusParam &instantMessageStatus);
    void onTypingIndication(const OnTypingIndicationParam &typingIndication);
};

#endif // CALLWINDOW_H
