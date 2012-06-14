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

TEMPLATE = app

SOURCES += main.cpp \
    looper.cpp

HEADERS += \
    looper.h
