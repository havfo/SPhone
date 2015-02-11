#include "call.h"

SCall::SCall(Account &acc, int call_id) : Call(acc, call_id) {
}

SCall::~SCall() {
}

void SCall::onCallState(OnCallStateParam &prm) {

}

void SCall::onCallMediaState(OnCallMediaStateParam &prm) {

}

void SCall::onInstantMessage(OnInstantMessageParam &prm) {

}

void SCall::onTypingIndication(OnTypingIndicationParam &prm) {

}
