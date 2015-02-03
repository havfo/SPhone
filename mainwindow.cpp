#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startApplication();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::startApplication()
{
    try {
        ep = new Endpoint;

        ep->libCreate();

        EpConfig ep_cfg;
        ep_cfg.logConfig.level = 1;

        ep->libInit(ep_cfg);

        TransportConfig tcfg;
        tcfg.port = 5060;
        TransportId tid = ep->transportCreate(PJSIP_TRANSPORT_UDP, tcfg);

        ep->libStart();
    } catch(Error& err) {
        std::cout << "Startup error: " << err.info() << std::endl;
    }
}

void MainWindow::on_call_button_clicked()
{

}

void MainWindow::on_chat_button_clicked()
{

}

void MainWindow::on_addContact_button_clicked()
{

}

void MainWindow::on_searchBox_textEdited(const QString &searchString)
{

}

void MainWindow::on_userAvailability_currentIndexChanged(int index)
{

}

void MainWindow::on_userLocation_returnPressed()
{

}

void MainWindow::on_userAvatar_clicked()
{

}

void MainWindow::on_accountSelector_currentIndexChanged(int index)
{

}

void MainWindow::on_quit_action_triggered()
{
    close();
}

void MainWindow::on_preferences_action_triggered()
{

}


void MainWindow::closeEvent(QCloseEvent *event)
{
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
