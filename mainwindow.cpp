#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <pjsua2.hpp>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    startApplication();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::startApplication() {

    loadSettings();

    try {
        ep = new Endpoint;

        ep->libCreate();

        EpConfig ep_cfg;
        ep_cfg.logConfig.level = logLevel;
        ep_cfg.logConfig.msgLogging = PJ_TRUE;

        ep->libInit(ep_cfg);

        TransportConfig tcfg;
        tcfg.port = udpPort;
        tID = ep->transportCreate(PJSIP_TRANSPORT_UDP, tcfg);

        tcfg.port = tcpPort;
        tID = ep->transportCreate(PJSIP_TRANSPORT_TCP, tcfg);

        TlsConfig tlcfg;
        tlcfg.CaListFile = "resources/tls/ca.pem";
        tlcfg.certFile = "resources/tls/cert.pem";
        tlcfg.privKeyFile = "resources/tls/key.pem";
        tcfg.port = tlsPort;
        tID = ep->transportCreate(PJSIP_TRANSPORT_TLS, tcfg);

        ep->libStart();
    } catch(Error& err) {
        std::cout << "Startup error: " << err.info() << std::endl;
    }

    am = new AccountManager();

    addAccounts();
}

void MainWindow::loadSettings() {
    QSettings settings("SPhone", "SPhone");

    firstRun = (settings.value("first_run", "").toString().toStdString().empty());

    if (firstRun) {
        // Do something for first run
        std::cout << "This is the first run of the application!" << std::endl;
    } else {
        std::cout << "This is not the first run of the application!" << std::endl;
        logLevel = settings.value("logLevel", "5").toInt();
        udpPort = settings.value("udpPort", "5060").toInt();
        tcpPort = settings.value("tcpPort", "5060").toInt();
        tlsPort = settings.value("tlsPort", "5061").toInt();
    }
}

void MainWindow::loadAccountSettings() {

}

void MainWindow::saveSettings() {

}

void MainWindow::onIncomingCall(SAccount *account, const OnIncomingCallParam &incomingCall) {
    std::cout << "Incoming call!" << std::endl;
}

void MainWindow::onRegState(SAccount *account, const OnRegStateParam &registrationState) {
    AccountInfo ai = account->getInfo();
    std::cout << (ai.regIsActive? "*** Register: code=" : "*** Unregister: code=")
                 << registrationState.code << std::endl;
}

void MainWindow::addAccounts() {
    AccountConfig acc_cfg;
    acc_cfg.idUri = "sip:test@example.com";
    acc_cfg.regConfig.registrarUri = "sip:example.com";
    acc_cfg.sipConfig.proxies.push_back("sip:sip.example.com;transport=tls");
    acc_cfg.sipConfig.authCreds.push_back( AuthCredInfo("digest", "*", "test", 0, "password") );

    SAccount *acc = new SAccount;

    try {
        acc->create(acc_cfg);

        qRegisterMetaType<OnRegStateParam>("OnRegStateParam");

        QObject::connect(acc, &SAccount::callIncoming, this, &MainWindow::onIncomingCall);
        QObject::connect(acc, &SAccount::registerState, this, &MainWindow::onRegState);

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
        delete am;

        ep->libDestroy();
        delete ep;

        saveSettings();

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
