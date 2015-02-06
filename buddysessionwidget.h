#ifndef BUDDYSESSIONWIDGET_H
#define BUDDYSESSIONWIDGET_H

#include <QWidget>
#include <QTextTable>
#include <QTextTableFormat>
#include <QTextCursor>
#include <QScrollBar>
#include "buddy.h"
#include "call.h"

namespace Ui {
class BuddySessionWidget;
}

class BuddySessionWidget : public QWidget {
    Q_OBJECT

public:
    explicit BuddySessionWidget(QWidget *parent = 0);
    ~BuddySessionWidget();

private slots:
    void on_chatButton_clicked();
    void on_callButton_clicked();
    void on_videoCallButton_clicked();
    void on_screenShareButton_clicked();
    void on_chatInput_returnPressed();

private:
    Ui::BuddySessionWidget *ui;
    QTextTableFormat tableFormat;
    void appendMessage(const QString &message);
    SBuddy *buddy;
};

#endif // BUDDYSESSIONWIDGET_H
