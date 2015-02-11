#ifndef CALLWINDOW_H
#define CALLWINDOW_H

#include <QDialog>
#include <pjsua2.hpp>
#include "call.h"

namespace Ui {
class CallWindow;
}

class CallWindow : public QDialog {
    Q_OBJECT

public:
    explicit CallWindow(QWidget *parent = 0);
    ~CallWindow();

    SCall *getCall() const;
    void setCall(SCall *call, bool incoming = true);
    bool isBusy() const;

private slots:
    void on_answer_button_clicked();
    void on_decline_button_clicked();

    void onCallState(const OnCallStateParam &callState);
    void onCallMediaState(const OnCallMediaStateParam &callMediaState);

private:
    Ui::CallWindow *ui;
    SCall *call;
    bool incoming;
    bool busy = false;
    bool answered = false;
    void closeWindow();
};

#endif // CALLWINDOW_H
