#-------------------------------------------------
#
# Project created by QtCreator 2012-06-13T14:16:26
#
#-------------------------------------------------

QT       += core phonon
QT       -= gui

QMAKE_CXXFLAGS += -std=c++0x

TARGET = ambiance
CONFIG   += console
CONFIG   -= app_bundle

target.path = /usr/local/bin
INSTALLS += target

TEMPLATE = app

SOURCES += main.cpp \
    looper.cpp \
    player.cpp \

HEADERS += \
    looper.h \
    player.h \
