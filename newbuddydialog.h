#ifndef NEWBUDDYDIALOG_H
#define NEWBUDDYDIALOG_H

#include <QDialog>
#include <QRegExp>
#include <QMessageBox>
#include <iostream>

namespace Ui {
class NewBuddyDialog;
}

class NewBuddyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewBuddyDialog(QWidget *parent = 0);
    ~NewBuddyDialog();
    QString displayName;
    QString sipAddress;
    bool subsribeToPresence;

    QString getDisplayName() const;
    QString getSipAddress() const;
    bool getSubsribeToPresence() const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::NewBuddyDialog *ui;
};

#endif // NEWBUDDYDIALOG_H
