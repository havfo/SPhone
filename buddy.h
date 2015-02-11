#ifndef BUDDY_H
#define BUDDY_H

#include <pjsua2.hpp>
#include <QString>
#include "account.h"

using namespace pj;

class SBuddy : public Buddy {

public:
    SBuddy(SAccount *account);
    void onBuddyState();

    bool getChatWindowOpen() const;
    void setChatWindowOpen(bool value);

    QString getDisplayName() const;
    void setDisplayName(const QString &value);

private:
    SAccount *account;
    bool chatWindowOpen;
    QString displayName;
};

#endif // BUDDY_H
