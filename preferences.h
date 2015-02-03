#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>

namespace Ui {
class Preferences;
}

class Preferences : public QDialog {
    Q_OBJECT

public:
    explicit Preferences(QWidget *parent = 0);
    ~Preferences();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_account_button_clicked();
    void on_device_button_clicked();
    void on_logging_button_clicked();
    void on_advanced_button_clicked();

private:
    Ui::Preferences *ui;
};

#endif // PREFERENCES_H
