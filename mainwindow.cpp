#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    startApplication();
    addAccounts();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::startApplication() {
    try {
        ep = new Endpoint;

        ep->libCreate();

        EpConfig ep_cfg;
        ep_cfg.logConfig.level = 1;

        ep->libInit(ep_cfg);

        TransportConfig tcfg;
        tcfg.port = 5060;
        tID = ep->transportCreate(PJSIP_TRANSPORT_UDP, tcfg);

        ep->libStart();
    } catch(Error& err) {
        std::cout << "Startup error: " << err.info() << std::endl;
    }

    am = new AccountManager();
}

void MainWindow::onIncomingCall(SAccount *account, OnIncomingCallParam &incomingCall) {
    std::cout << "Incoming call!" << std::endl;
}

void MainWindow::onAccountRegisterState(SAccount *account, OnRegStateParam &regState) {
    AccountInfo ai = account->getInfo();
    std::cout << (ai.regIsActive? "*** Register: code=" : "*** Unregister: code=")
                 << regState.code << std::endl;
}

void MainWindow::addAccounts() {
    AccountConfig acc_cfg;
    acc_cfg.idUri = "sip:test@example.com";
    acc_cfg.regConfig.registrarUri = "sip:example.com";
    acc_cfg.sipConfig.proxies.push_back("sip:xxx.example.com");
    acc_cfg.sipConfig.authCreds.push_back( AuthCredInfo("digest", "*", "username", 0, "password") );

    SAccount *acc = new SAccount;

    try {
        acc->create(acc_cfg);

        QObject::connect(acc, &SAccount::callIncoming, this, &MainWindow::onIncomingCall);
        QObject::connect(acc, &SAccount::registerState, this, &MainWindow::onAccountRegisterState);

        am->addAccount(acc);
    } catch(Error& err) {
        std::cout << "Account creation error: " << err.info() << std::endl;
    }
}

void MainWindow::on_call_button_clicked() {

}

void MainWindow::on_chat_button_clicked() {

}

void MainWindow::on_searchBox_textEdited(const QString &searchString) {
    // std::cout << "String typed: " << searchString.toStdString() << std::endl;

    if (!searchString.trimmed().isEmpty() && ui->stackedWidget->currentIndex() != 1) {
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_userAvailability_currentIndexChanged(int index) {

}

void MainWindow::on_userLocation_returnPressed() {

}

void MainWindow::on_userAvatar_clicked() {

}

void MainWindow::on_accountSelector_currentIndexChanged(int index) {

}

void MainWindow::on_quit_action_triggered() {
    close();
}

void MainWindow::on_preferences_action_triggered() {
    p = new Preferences(this, am);

    int returnCode = p->exec();

    if (returnCode == QDialog::Accepted) {

        // Do some setting up of account stuff
    }
}


void MainWindow::closeEvent(QCloseEvent *event) {
    if (reallyExit()) {
        ep->libDestroy();
        delete ep;
        event->accept();
    } else {
        event->ignore();
    }
}

bool MainWindow::reallyExit() {
    QMessageBox::StandardButton ret;
    ret = QMessageBox::question(this, tr("SPhone"),
            tr("Do you really want to exit?"), QMessageBox::Yes
                    | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        return true;
    } else {
        return false;
    }
}

void MainWindow::on_addcontact_button_clicked() {

}

void MainWindow::on_backtocontacts_button_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}
