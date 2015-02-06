#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <pjsua2.hpp>
#include <QObject>

using namespace pj;

class SAccount : public QObject, public Account {
    Q_OBJECT

public:
    SAccount();

private slots:
    virtual void onIncomingCall(OnIncomingCallParam &incomingCall);
    virtual void onRegStarted(OnRegStartedParam &regStarted);
    virtual void onIncomingSubscribe(OnIncomingSubscribeParam &subscribe);
    virtual void onInstantMessage(OnInstantMessageParam &instantMessage);
    virtual void onInstantMessageStatus(OnInstantMessageStatusParam &instantMessageStatus);
    virtual void onTypingIndication(OnTypingIndicationParam &typingIndication);
    virtual void onMwiInfo(OnMwiInfoParam &mwiInfo);
    virtual void onRegState(OnRegStateParam &registrationState);

signals:
    void callIncoming(SAccount *, const OnIncomingCallParam &);
    void registerState(SAccount *, const OnRegStateParam &);
    void registerStarted(SAccount *, const OnRegStartedParam &regStarted);
    void subscribeIncoming(SAccount *, const OnIncomingSubscribeParam &subscribe);
    void instantMessageIncoming(SAccount *, const OnInstantMessageParam &instantMessage);
    void incomingMessageStatus(SAccount *, const OnInstantMessageStatusParam &instantMessageStatus);
    void incomingTypingIndication(SAccount *, const OnTypingIndicationParam &typingIndication);
    void incomingMwiInfo(SAccount *, const OnMwiInfoParam &mwiInfo);
};

#endif // ACCOUNT_H
