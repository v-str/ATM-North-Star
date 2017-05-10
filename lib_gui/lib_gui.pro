QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
TARGET = lib_gui

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang

DEPENDPATH += \
    ../atm_splash_screen \
    ../features \
    ../images \

INCLUDEPATH += \
    $$PWD/atm_splash_screen \
    $$PWD/features \

HEADERS += \
    $$PWD/atm_splash_screen/*.h \
    $$PWD/features/*.h \

SOURCES += \
    $$PWD/atm_splash_screen/*.cpp \
    $$PWD/features/*.cpp \

FORMS += \
    $$PWD/atm_splash_screen/*.ui \

RESOURCES += \
    atm_resources.qrc









