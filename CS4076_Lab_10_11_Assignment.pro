#-------------------------------------------------
#
# Project created by QtCreator 2019-02-26T09:08:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CS4076_Lab_6
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
        main.cpp \
        mainwindow.cpp \
    Character.cpp \
    Command.cpp \
    CommandWords.cpp \
    item.cpp \
    Parser.cpp \
    Room.cpp \
    ZorkUL.cpp \
    Quiz.cpp

HEADERS += \
        mainwindow.h \
    Character.h \
    Command.h \
    CommandWords.h \
    item.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    Quiz.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    ../CS4076-Lab1/CS4076-Lab1.pro \
    ../CS4076-Lab1/CS4076-Lab1.pro

RESOURCES += \
    assets.qrc

DISTFILES += \
    README.txt
