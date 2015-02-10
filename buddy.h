#ifndef BUDDY_H
#define BUDDY_H

#include <pjsua2.hpp>
#include "account.h"

using namespace pj;

class SBuddy : public Buddy {

public:
    SBuddy(SAccount *account);
    void onBuddyState();

    bool getChatWindowOpen() const;
    void setChatWindowOpen(bool value);

private:
    SAccount *account;
    bool chatWindowOpen;
};

#endif // BUDDY_H
