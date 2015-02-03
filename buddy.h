#ifndef BUDDY_H
#define BUDDY_H

#include <pjsua2.hpp>

using namespace pj;

class SBuddy : public Buddy
{
public:
    SBuddy();

    // Buddy interface
public:
    void onBuddyState();
};

#endif // BUDDY_H
