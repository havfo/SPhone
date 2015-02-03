#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <pjsua2.hpp>

using namespace pj;

class SPhoneAccount : public Account
{
    // Account interface
public:
    SPhoneAccount();
    virtual void onIncomingCall(OnIncomingCallParam &incomingCall);
    virtual void onRegStarted(OnRegStartedParam &regStarted);
    virtual void onIncomingSubscribe(OnIncomingSubscribeParam &subscribe);
    virtual void onInstantMessage(OnInstantMessageParam &instantMessage);
    virtual void onInstantMessageStatus(OnInstantMessageStatusParam &instantMessageStatus);
    virtual void onTypingIndication(OnTypingIndicationParam &typingIndication);
    virtual void onMwiInfo(OnMwiInfoParam &mwiInfo);
    virtual void onRegState(OnRegStateParam &regState);
};

#endif // ACCOUNT_H
