#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <QList>
#include <QString>
#include "account.h"

class AccountManager {

public:
    AccountManager();
    bool addAccount(SAccount *account);
    SAccount* getAccount(int id);
    SAccount* getAccount(QString sipUri);
    void deleteAccount(SAccount *account);

private:
    QList<SAccount *> accounts;

};

#endif // ACCOUNTMANAGER_H
