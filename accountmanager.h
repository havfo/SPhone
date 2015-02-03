#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <QList>
#include "account.h"

class AccountManager
{

public:
    AccountManager();
    bool addAccount(SAccount &account);
    SAccount& getAccount(int id);

private:
    QList<SAccount *> accounts;

};

#endif // ACCOUNTMANAGER_H
