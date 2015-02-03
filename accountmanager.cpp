#include "accountmanager.h"

AccountManager::AccountManager(QWidget *parent) {
    this->parent = parent;
}

bool AccountManager::addAccount(SAccount *account) {
    accounts << account;
}

SAccount *AccountManager::getAccount(int id) {
    return accounts.at(id);
}

SAccount *AccountManager::getAccount(QString sipUri) {
    SAccount *account;

    for (int i=0; i<accounts.size(); i++) {
        account = accounts.at(i);
        if (sipUri.trimmed().toStdString() == account->getInfo().uri) {
            return account;
        }
    }
    return 0;
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

QList<SAccount *> AccountManager::getAccounts() {
    return accounts;
}
