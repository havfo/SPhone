#ifndef BUDDY_H
#define BUDDY_H

#include <pjsua2.hpp>
#include "account.h"

using namespace pj;

class SBuddy : public Buddy {

public:
    SBuddy(SAccount *account);
    void onBuddyState();

private:
    SAccount *account;
};

#endif // BUDDY_H
