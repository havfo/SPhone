#include "accountmanager.h"

AccountManager::AccountManager() {



}

bool AccountManager::addAccount(SAccount *account) {
    accounts << account;
}



SAccount *AccountManager::getAccount(int id) {
    return accounts.at(id);
}

SAccount *AccountManager::getAccount(QString sipUri) {

}

void AccountManager::deleteAccount(SAccount *account) {
    QList<SAccount*>::iterator i;

    if (!account) {
        return;
    }

    for (i = accounts.begin(); i != accounts.end(); i++) {
        if ((*i) == account) {
            accounts.erase(i);

            delete account;
            break;
        }
    }
}
