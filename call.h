#ifndef CALL_H
#define CALL_H

#include <pjsua2.hpp>
#include <QObject>

using namespace pj;

class SCall : public QObject, public Call {
    Q_OBJECT

public:
    SCall(Account &acc, int call_id = PJSUA_INVALID_ID);
    ~SCall();

    // Call interface
private slots:
    virtual void onCallState(OnCallStateParam &prm);
    virtual void onCallTsxState(OnCallTsxStateParam &prm);
    virtual void onCallMediaState(OnCallMediaStateParam &prm);
    virtual void onCallSdpCreated(OnCallSdpCreatedParam &prm);
    virtual void onStreamCreated(OnStreamCreatedParam &prm);
    virtual void onStreamDestroyed(OnStreamDestroyedParam &prm);
    virtual void onDtmfDigit(OnDtmfDigitParam &prm);
    virtual void onCallTransferRequest(OnCallTransferRequestParam &prm);
    virtual void onCallTransferStatus(OnCallTransferStatusParam &prm);
    virtual void onCallReplaceRequest(OnCallReplaceRequestParam &prm);
    virtual void onCallReplaced(OnCallReplacedParam &prm);
    virtual void onCallRxOffer(OnCallRxOfferParam &prm);
    virtual void onInstantMessage(OnInstantMessageParam &prm);
    virtual void onInstantMessageStatus(OnInstantMessageStatusParam &prm);
    virtual void onTypingIndication(OnTypingIndicationParam &prm);
    virtual pjsip_redirect_op onCallRedirected(OnCallRedirectedParam &prm);
    virtual void onCallMediaTransportState(OnCallMediaTransportStateParam &prm);
    virtual void onCallMediaEvent(OnCallMediaEventParam &prm);
    virtual void onCreateMediaTransport(OnCreateMediaTransportParam &prm);
};

#endif // CALL_H
