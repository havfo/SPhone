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
    accountmanager.cpp

HEADERS  += mainwindow.h \
    account.h \
    accountmanager.h

FORMS    += resources/mainwindow.ui

RESOURCES += \
    resources/resources.qrc

unix|win32: LIBS += -lpjsua2
