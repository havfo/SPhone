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

signals:
    void onCallStateSignal(const OnCallStateParam &);
    void onCallMediaStateSignal(const OnCallMediaStateParam &);
};

#endif // CALL_H
