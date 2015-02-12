#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <pjsua2.hpp>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    buddyListModel = new SBuddyListModel(buddies);
    this->ui->buddyList->setModel(buddyListModel);

    this->ui->call_button->setEnabled(false);
    this->ui->chat_button->setEnabled(false);

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

    startConversation();
}

void MainWindow::loadSettings() {
    QSettings settings(QString("config/config.ini"), QSettings::IniFormat);

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

void MainWindow::startConversation() {
    chatWin = new ChatWindow(this);

    chatWin->show();
}

void MainWindow::saveSettings() {

}

void MainWindow::onIncomingCall(SAccount *account, SCall *call) {
    std::cout << "Incoming call!" << std::endl;

    if (callWin == NULL || !callWin->isVisible()) { // We are not in a call
        delete callWin;

        callWin = new CallWindow;
        callWin->show();

        callWin->setCall(call);
    } else { // We are inn a call
        CallOpParam prm;
        prm.statusCode = PJSIP_SC_DECLINE;
        call->hangup(prm);

        delete call;
    }
}

void MainWindow::onInstantMessage(SAccount *account, const OnInstantMessageParam &instantMessage) {
    // Check if FROM field exists in buddy list
}

void MainWindow::onTypingIndication(SAccount *account, const OnTypingIndicationParam &typingIndication) {
    // Check if FROM field exists in buddy list
}

void MainWindow::addAccounts() {
    QSettings settings(QString("config/config.ini"), QSettings::IniFormat);

    AccountConfig acc_cfg;
    acc_cfg.idUri = settings.value("sipURI", "").toString().toStdString();
    acc_cfg.regConfig.registrarUri = "sip:example.com";
    acc_cfg.sipConfig.proxies.push_back("sip:sip.example.com;transport=tls");
    acc_cfg.sipConfig.authCreds.push_back( AuthCredInfo("digest", "*", "test", 0, "password") );

    SAccount *acc = new SAccount;

    try {
        acc->create(acc_cfg);

        qRegisterMetaType<OnIncomingCallParam>("OnIncomingCallParam");
        qRegisterMetaType<OnInstantMessageParam>("OnInstantMessageParam");
        qRegisterMetaType<OnTypingIndicationParam>("OnTypingIndicationParam");


        QObject::connect(acc, &SAccount::callIncoming, this, &MainWindow::onIncomingCall);
        QObject::connect(acc, &SAccount::instantMessageIncoming, this, &MainWindow::onInstantMessage);
        QObject::connect(acc, &SAccount::incomingTypingIndication, this, &MainWindow::onTypingIndication);

        am->addAccount(acc);
    } catch(Error& err) {
        std::cout << "Account creation error: " << err.info() << std::endl;
    }
}

void MainWindow::on_call_button_clicked() {
    // Check what is selected
    if (!this->ui->searchBox->text().trimmed().isEmpty()) {
        // There has been typed something, try calling to it

        QString sipAddressRegExp = "\\bsip:[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}\\b";
        QRegExp rx(sipAddressRegExp);

        QString sipAddress = this->ui->searchBox->text();

        if (rx.exactMatch(sipAddress)) {
            // Full SIP URI

        } else if (rx.exactMatch("sip:" + sipAddress)) {
            sipAddress = "sip:" + sipAddress;
            // Now full SIP URI

        } else {
            QMessageBox ret;
            ret.setText("Invalid SIP Address");
            ret.exec();

            return;
        }


    }
}

void MainWindow::on_chat_button_clicked() {

}

void MainWindow::on_newContact_button_clicked() {
    nb = new NewBuddyDialog(this);

    int returnCode = nb->exec();

    if (returnCode == QDialog::Accepted) {
        // Add new buddy
    }
}

void MainWindow::on_searchBox_textEdited(const QString &searchString) {
    // std::cout << "String typed: " << searchString.toStdString() << std::endl;

    if (!searchString.trimmed().isEmpty() && ui->stackedWidget->currentIndex() != 1) {
        ui->stackedWidget->setCurrentIndex(1);
        this->ui->call_button->setEnabled(true);
        this->ui->chat_button->setEnabled(true);
    } else {
        ui->stackedWidget->setCurrentIndex(0);
        this->ui->call_button->setEnabled(false);
        this->ui->chat_button->setEnabled(false);
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

void MainWindow::on_addcontact_button_clicked() {

}

void MainWindow::on_backtocontacts_button_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

// Selected a buddy
void MainWindow::on_buddyList_clicked(const QModelIndex &index) {
    this->ui->call_button->setEnabled(true);
    this->ui->chat_button->setEnabled(true);
}

// Double clicked a buddy
void MainWindow::on_buddyList_doubleClicked(const QModelIndex &index) {
    // Find buddy and start call window
}

void MainWindow::on_backtocontacts2_button_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
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
