#ifndef ACCOUNTWIZARD_H
#define ACCOUNTWIZARD_H

#include <QDialog>

namespace Ui {
class AccountWizard;
}

class AccountWizard : public QDialog
{
    Q_OBJECT

public:
    explicit AccountWizard(QWidget *parent = 0);
    ~AccountWizard();

private:
    Ui::AccountWizard *ui;
};

#endif // ACCOUNTWIZARD_H
