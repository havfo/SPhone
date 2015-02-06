#include "callwindow.h"
#include "ui_callwindow.h"

callWindow::callWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::callWindow)
{
    ui->setupUi(this);
}

callWindow::~callWindow()
{
    delete ui;
}
