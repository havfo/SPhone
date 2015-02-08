#-------------------------------------------------
#
# Project created by QtCreator 2015-02-02T21:26:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SPhone
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    account.cpp \
    accountmanager.cpp \
    buddy.cpp \
    preferences.cpp \
    accountwizard.cpp \
    callwindow.cpp \
    call.cpp \
    sbuddylistmodel.cpp \
    buddysessionwidget.cpp \
    newbuddydialog.cpp

HEADERS  += mainwindow.h \
    account.h \
    accountmanager.h \
    buddy.h \
    preferences.h \
    accountwizard.h \
    callwindow.h \
    call.h \
    sbuddylistmodel.h \
    buddysessionwidget.h \
    newbuddydialog.h

FORMS    += resources/mainwindow.ui \
    resources/preferences.ui \
    resources/preferences.ui \
    resources/accountwizard.ui \
    resources/callwindow.ui \
    resources/buddysessionwidget.ui \
    resources/newbuddydialog.ui

RESOURCES += \
    resources/resources.qrc

unix|win32: LIBS += -lpjsua2
