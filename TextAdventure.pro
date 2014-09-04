#-------------------------------------------------
#
# Project created by QtCreator 2014-08-25T13:11:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    itemmanager.cpp \
    item.cpp \
    inventory.cpp \
    player.cpp \
    areamanager.cpp \
    area.cpp \
    people.cpp \
    editor.cpp

HEADERS  += mainwindow.h \
    game.h \
    itemmanager.h \
    item.h \
    inventory.h \
    player.h \
    areamanager.h \
    area.h \
    people.h \
    editor.h

FORMS    += mainwindow.ui \
    editor.ui
