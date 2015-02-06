#ifndef CALLWINDOW_H
#define CALLWINDOW_H

#include <QDialog>
#include <QList>
#include <pjsua2.hpp>
#include "account.h"
#include "buddy.h"
#include "call.h"
#include "sbuddylistmodel.h"
#include "buddysessionwidget.h"

namespace Ui {
class CallWindow;
}

class CallWindow : public QDialog {
    Q_OBJECT

public:
    explicit CallWindow(QWidget *parent = 0);
    ~CallWindow();
    void incomingCallFromBuddy(SBuddy *buddy, const OnIncomingCallParam &incomingCall);
    void incomingChatFromBuddy(SBuddy *buddy, const OnInstantMessageParam &instantMessage);
    void outgoingCallToBuddy(SBuddy *buddy);
    void outgoingChatToBuddy(SBuddy *buddy);
    void incomingTypingIndication(SBuddy *buddy, const OnTypingIndicationParam &typingIndication);

private:
    Ui::CallWindow *ui;
    QList<SBuddy *> buddies;
    QList<SCall *> calls;
    SBuddyListModel *buddyListModel;
    QList<BuddySessionWidget *> buddySessions;
    int currentSelectedBuddy;
    SAccount *account;

private slots:
    void on_buddyList_clicked(const QModelIndex &index);
};

#endif // CALLWINDOW_H
