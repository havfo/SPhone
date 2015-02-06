#include "account.h"

SAccount::SAccount() {
}

void SAccount::onIncomingCall(OnIncomingCallParam &incomingCall) {
    emit callIncoming(this, incomingCall);
}

void SAccount::onRegStarted(OnRegStartedParam &regStarted) {
    emit registerStarted(this, regStarted);
}

void SAccount::onIncomingSubscribe(OnIncomingSubscribeParam &subscribe) {
    emit subscribeIncoming(this, subscribe);
}

void SAccount::onInstantMessage(OnInstantMessageParam &instantMessage) {
    emit instantMessageIncoming(this, instantMessage);
}

void SAccount::onInstantMessageStatus(OnInstantMessageStatusParam &instantMessageStatus) {
    emit incomingMessageStatus(this, instantMessageStatus);
}

void SAccount::onTypingIndication(OnTypingIndicationParam &typingIndication) {
    emit incomingTypingIndication(this, typingIndication);
}

void SAccount::onMwiInfo(OnMwiInfoParam &mwiInfo) {
    emit incomingMwiInfo(this, mwiInfo);
}

void SAccount::onRegState(OnRegStateParam &registrationState) {
    emit registerState(this, registrationState);
}
