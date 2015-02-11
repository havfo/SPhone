#include "account.h"

SAccount::SAccount() {
}

void SAccount::onIncomingCall(OnIncomingCallParam &incomingCall) {
    emit callIncoming(this, incomingCall);
}

void SAccount::onIncomingSubscribe(OnIncomingSubscribeParam &subscribe) {
    emit subscribeIncoming(this, subscribe);
}

void SAccount::onInstantMessage(OnInstantMessageParam &instantMessage) {
    emit instantMessageIncoming(this, instantMessage);
}

void SAccount::onTypingIndication(OnTypingIndicationParam &typingIndication) {
    emit incomingTypingIndication(this, typingIndication);
}

void SAccount::onRegState(OnRegStateParam &registrationState) {
    emit registerState(this, registrationState);
}

QString SAccount::getDisplayName() const {
    return displayName;
}

void SAccount::setDisplayName(const QString &displayName) {
    this->displayName = displayName;
}

