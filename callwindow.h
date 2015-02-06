#ifndef CALLWINDOW_H
#define CALLWINDOW_H

#include <QDialog>
#include <QList>
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
    void addBuddyToChat(SBuddy *buddy);
    void addBuddyToCall(SBuddy *buddy);

private:
    Ui::CallWindow *ui;
    QList<SBuddy *> buddies;
    QList<SCall *> calls;
    SBuddyListModel *buddiesListModel;
    QList<BuddySessionWidget *> buddySessions;
    int currentBuddy;

private slots:
    void on_buddyList_clicked(const QModelIndex &index);
};

#endif // CALLWINDOW_H
