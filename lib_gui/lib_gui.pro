QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
TARGET = lib_gui

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang++

DEPENDPATH += \
    ../initial_screen \
    ../main_screen \
    ../features \
    ../images \

INCLUDEPATH += \
    $$PWD/initial_screen \
    $$PWD/main_screen \
    $$PWD/features \

HEADERS += \
    $$PWD/initial_screen/*.h \
    $$PWD/main_screen/*.h \
    $$PWD/features/*.h \

SOURCES += \
    $$PWD/initial_screen/*.cpp \
    $$PWD/main_screen/*.cpp \
    $$PWD/features/*.cpp \

FORMS += \
    $$PWD/initial_screen/*.ui \
    $$PWD/main_screen/*.ui \

RESOURCES += \
    atm_resources.qrc










