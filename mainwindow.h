#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include "accountmanager.h"
#include "preferences.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

protected:
    virtual void closeEvent(QCloseEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AccountManager *am;
    Endpoint *ep;
    QList<Buddy *> buddies;
    TransportId tID;
    Preferences *p;
    void startApplication();
    void loadSettings();
    void saveSettings();
    bool reallyExit();

private slots:
    void on_call_button_clicked();
    void on_chat_button_clicked();
    void on_addContact_button_clicked();
    void on_searchBox_textEdited(const QString &searchString);
    void on_userAvailability_currentIndexChanged(int index);
    void on_userLocation_returnPressed();
    void on_userAvatar_clicked();
    void on_accountSelector_currentIndexChanged(int index);
    void on_quit_action_triggered();
    void on_preferences_action_triggered();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
