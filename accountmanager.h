#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <QList>
#include <QString>
#include "account.h"

class AccountManager {

public:
    AccountManager(QWidget *parent = 0);
    bool addAccount(SAccount *account);
    SAccount* getAccount(int id);
    SAccount* getAccount(QString sipUri);
    void deleteAccount(SAccount *account);
    QList<SAccount *> getAccounts();

private:
    QList<SAccount *> accounts;
    QWidget *parent;

};

#endif // ACCOUNTMANAGER_H
