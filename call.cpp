#include "call.h"

SCall::SCall(Account &acc, int call_id) : Call(acc, call_id) {
}

SCall::~SCall() {
}

void SCall::onCallState(OnCallStateParam &prm) {

}

void SCall::onCallTsxState(OnCallTsxStateParam &prm) {

}

void SCall::onCallMediaState(OnCallMediaStateParam &prm) {

}

void SCall::onCallSdpCreated(OnCallSdpCreatedParam &prm) {

}

void SCall::onStreamCreated(OnStreamCreatedParam &prm) {

}

void SCall::onStreamDestroyed(OnStreamDestroyedParam &prm) {

}

void SCall::onDtmfDigit(OnDtmfDigitParam &prm) {

}

void SCall::onCallTransferRequest(OnCallTransferRequestParam &prm) {

}

void SCall::onCallTransferStatus(OnCallTransferStatusParam &prm) {

}

void SCall::onCallReplaceRequest(OnCallReplaceRequestParam &prm) {

}

void SCall::onCallReplaced(OnCallReplacedParam &prm) {

}

void SCall::onCallRxOffer(OnCallRxOfferParam &prm) {

}

void SCall::onInstantMessage(OnInstantMessageParam &prm) {

}

void SCall::onInstantMessageStatus(OnInstantMessageStatusParam &prm) {

}

void SCall::onTypingIndication(OnTypingIndicationParam &prm) {

}

pjsip_redirect_op SCall::onCallRedirected(OnCallRedirectedParam &prm) {

}

void SCall::onCallMediaTransportState(OnCallMediaTransportStateParam &prm) {

}

void SCall::onCallMediaEvent(OnCallMediaEventParam &prm) {

}

void SCall::onCreateMediaTransport(OnCreateMediaTransportParam &prm) {

}
