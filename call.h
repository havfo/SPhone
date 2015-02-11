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
    virtual void onCallMediaState(OnCallMediaStateParam &prm);
    virtual void onInstantMessage(OnInstantMessageParam &prm);
    virtual void onTypingIndication(OnTypingIndicationParam &prm);
};

#endif // CALL_H
