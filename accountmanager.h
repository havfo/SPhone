#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <QList>
#include "account.h"

class AccountManager
{

public:
    AccountManager();
    bool addAccount(SPhoneAccount &account);
    SPhoneAccount& getAccount(int id);

private:
    QList<SPhoneAccount *> accounts;

};

#endif // ACCOUNTMANAGER_H
