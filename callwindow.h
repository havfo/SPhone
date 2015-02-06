#ifndef CALLWINDOW_H
#define CALLWINDOW_H

#include <QDialog>

namespace Ui {
class callWindow;
}

class callWindow : public QDialog
{
    Q_OBJECT

public:
    explicit callWindow(QWidget *parent = 0);
    ~callWindow();

private:
    Ui::callWindow *ui;
};

#endif // CALLWINDOW_H
