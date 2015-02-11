#include "callwindow.h"
#include "ui_callwindow.h"

CallWindow::CallWindow(QWidget *parent) : QDialog(parent), ui(new Ui::CallWindow) {
    ui->setupUi(this);
}

CallWindow::~CallWindow() {
    delete ui;
}

void CallWindow::on_answer_button_clicked() {
    CallOpParam prm;
    prm.statusCode = PJSIP_SC_OK;
    call->answer(prm);

    answered = true;

    this->ui->answer_button->hide();
    this->ui->decline_button->setText("Hangup");
}

void CallWindow::on_decline_button_clicked() {
    CallOpParam prm;

    if (incoming && !answered) { // Decline call
        prm.statusCode = PJSIP_SC_DECLINE;
    }

    call->hangup(prm);
    busy = false;

    closeWindow();
}

void CallWindow::onCallState(const OnCallStateParam &callState) {
    CallInfo ci = call->getInfo();
    if (ci.state == PJSIP_INV_STATE_DISCONNECTED) {
        busy = false;
        delete call;

        closeWindow();
    }
}

void CallWindow::onCallMediaState(const OnCallMediaStateParam &callMediaState) {

}

void CallWindow::closeWindow() {
    this->hide();
    this->deleteLater();
    this->close();
}

bool CallWindow::isBusy() const {
    return busy;
}

SCall *CallWindow::getCall() const {
    return call;
}

void CallWindow::setCall(SCall *call, bool incoming) {
    this->call = call;
    this->incoming = incoming;

    busy = true;

    if (!incoming) {
        this->ui->answer_button->hide();
        this->ui->decline_button->setText("Hangup");
    }

    QObject::connect(this->call, &SCall::onCallStateSignal, this, &CallWindow::onCallState);
    QObject::connect(this->call, &SCall::onCallMediaStateSignal, this, &CallWindow::onCallMediaState);
}

