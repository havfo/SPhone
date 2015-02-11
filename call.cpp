#include "call.h"

SCall::SCall(Account &acc, int call_id) : Call(acc, call_id) {
}

SCall::~SCall() {
}

void SCall::onCallState(OnCallStateParam &prm) {
    emit onCallStateSignal(prm);
}

void SCall::onCallMediaState(OnCallMediaStateParam &prm) {
    emit onCallMediaStateSignal(prm);
}
