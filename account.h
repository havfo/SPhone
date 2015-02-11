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
    QString getDisplayName() const;
    void setDisplayName(const QString &displayName);

private slots:
    virtual void onIncomingCall(OnIncomingCallParam &incomingCall);
    virtual void onIncomingSubscribe(OnIncomingSubscribeParam &subscribe);
    virtual void onInstantMessage(OnInstantMessageParam &instantMessage);
    virtual void onTypingIndication(OnTypingIndicationParam &typingIndication);
    virtual void onRegState(OnRegStateParam &registrationState);

signals:
    void callIncoming(SAccount *, const OnIncomingCallParam &);
    void registerState(SAccount *, const OnRegStateParam &);
    void subscribeIncoming(SAccount *, const OnIncomingSubscribeParam &);
    void instantMessageIncoming(SAccount *, const OnInstantMessageParam &);
    void incomingTypingIndication(SAccount *, const OnTypingIndicationParam &typingIndication);

private:
    QString displayName;
};

#endif // ACCOUNT_H
