#include "account.h"

SAccount::SAccount() {
}

void SAccount::onIncomingCall(OnIncomingCallParam &incomingCall) {
    SCall *call = new SCall(*this, incomingCall.callId);

    emit callIncoming(this, call);
}

void SAccount::onInstantMessage(OnInstantMessageParam &instantMessage) {
    emit instantMessageIncoming(this, instantMessage);
}

void SAccount::onTypingIndication(OnTypingIndicationParam &typingIndication) {
    emit incomingTypingIndication(this, typingIndication);
}

QString SAccount::getDisplayName() const {
    return displayName;
}

void SAccount::setDisplayName(const QString &displayName) {
    this->displayName = displayName;
}

