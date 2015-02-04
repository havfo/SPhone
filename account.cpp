#include "account.h"

SAccount::SAccount() {
}

void SAccount::onIncomingCall(OnIncomingCallParam &incomingCall) {
    emit callIncoming(this, incomingCall);
}

void SAccount::onRegStarted(OnRegStartedParam &regStarted) {

}

void SAccount::onIncomingSubscribe(OnIncomingSubscribeParam &subscribe) {

}

void SAccount::onInstantMessage(OnInstantMessageParam &instantMessage) {

}

void SAccount::onInstantMessageStatus(OnInstantMessageStatusParam &instantMessageStatus) {

}

void SAccount::onTypingIndication(OnTypingIndicationParam &typingIndication) {

}

void SAccount::onMwiInfo(OnMwiInfoParam &mwiInfo) {

}

void SAccount::onRegState(OnRegStateParam &regState) {
    emit registerState(this, regState);
}
