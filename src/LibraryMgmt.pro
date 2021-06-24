#-------------------------------------------------
#
# Project created by QtCreator 2019-07-27T12:07:27
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LibraryMgmt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        addentry.cpp \
        adminpanel.cpp \
        editwindow.cpp \
        main.cpp \
        mainwindow.cpp \
        search.cpp \
        updatepw.cpp \
        window.cpp

HEADERS += \
        addentry.h \
        adminpanel.h \
        editwindow.h \
        mainwindow.h \
        search.h \
        updatepw.h \
        window.h

FORMS += \
        addentry.ui \
        adminpanel.ui \
        editwindow.ui \
        mainwindow.ui \
        search.ui \
        updatepw.ui \
        window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
