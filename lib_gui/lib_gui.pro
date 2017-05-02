QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
TARGET = lib_gui

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache g++

DEPENDPATH += \
    ../initial_form \
    ../features \
    ../images \

INCLUDEPATH += \
    $$PWD/initial_form \
    $$PWD/features \

HEADERS += \
    $$PWD/initial_form/*.h \
    $$PWD/features/*.h \

SOURCES += \
    $$PWD/initial_form/*.cpp \
    $$PWD/features/*.cpp \

FORMS += \
    $$PWD/initial_form/*.ui \

RESOURCES += \
    atm_resources.qrc









