#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <pjsua2.hpp>
#include <QObject>
#include "call.h"

using namespace pj;

class SAccount : public QObject, public Account {
    Q_OBJECT

public:
    SAccount();
    QString getDisplayName() const;
    void setDisplayName(const QString &displayName);

private slots:
    virtual void onIncomingCall(OnIncomingCallParam &incomingCall);
    virtual void onInstantMessage(OnInstantMessageParam &instantMessage);
    virtual void onTypingIndication(OnTypingIndicationParam &typingIndication);

signals:
    void callIncoming(SAccount *, SCall *);
    void instantMessageIncoming(SAccount *, const OnInstantMessageParam &);
    void incomingTypingIndication(SAccount *, const OnTypingIndicationParam &typingIndication);

private:
    QString displayName;
};

#endif // ACCOUNT_H
