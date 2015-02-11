#include "buddy.h"

// account : The account this buddy belongs to
SBuddy::SBuddy(SAccount *account) {
    this->account = account;
}

void SBuddy::onBuddyState() {

}

bool SBuddy::getChatWindowOpen() const {
    return chatWindowOpen;
}

void SBuddy::setChatWindowOpen(bool value) {
    chatWindowOpen = value;
}

QString SBuddy::getDisplayName() const {
    return displayName;
}

void SBuddy::setDisplayName(const QString &value) {
    displayName = value;
}

