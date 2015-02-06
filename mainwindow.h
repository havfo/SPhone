#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QSettings>
#include "buddy.h"
#include "accountmanager.h"
#include "preferences.h"
#include "callwindow.h"
#include "sbuddylistmodel.h"

using namespace pj;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

protected:
    virtual void closeEvent(QCloseEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SBuddyListModel *buddyListModel;
    AccountManager *am;
    Endpoint *ep;
    QList<SBuddy *> buddies;
    TransportId tID;
    Preferences *p;
    CallWindow *c;

    int logLevel;
    int udpPort;
    int tcpPort;
    int tlsPort;

    bool firstRun;

    void startApplication();
    void loadSettings();
    void saveSettings();
    bool reallyExit();
    void addAccounts();
    void loadAccountSettings();
    void startConversation();

private slots:
    void on_call_button_clicked();
    void on_chat_button_clicked();
    void on_searchBox_textEdited(const QString &searchString);
    void on_userAvailability_currentIndexChanged(int index);
    void on_userLocation_returnPressed();
    void on_userAvatar_clicked();
    void on_accountSelector_currentIndexChanged(int index);
    void on_quit_action_triggered();
    void on_preferences_action_triggered();
    void on_addcontact_button_clicked();
    void on_backtocontacts_button_clicked();

    // Slots for signals from accounts
    void onIncomingCall(SAccount *account, const OnIncomingCallParam &incomingCall);
    void onRegState(SAccount *account, const OnRegStateParam &registrationState);
    void onRegStarted(SAccount *account, const OnRegStartedParam &regStarted);
    void onIncomingSubscribe(SAccount *account, const OnIncomingSubscribeParam &subscribe);
    void onInstantMessage(SAccount *account, const OnInstantMessageParam &instantMessage);
    void onInstantMessageStatus(SAccount *account, const OnInstantMessageStatusParam &instantMessageStatus);
    void onTypingIndication(SAccount *account, const OnTypingIndicationParam &typingIndication);
    void onMwiInfo(SAccount *account, const OnMwiInfoParam &mwiInfo);
    void on_buddyList_clicked(const QModelIndex &index);
    void on_buddyList_doubleClicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
