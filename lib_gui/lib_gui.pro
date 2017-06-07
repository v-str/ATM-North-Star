QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
TARGET = lib_gui

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang++

DEPENDPATH += \
    ../atm_widgets \
    ../features \
    ../images \

INCLUDEPATH += \
    $$PWD/atm_widgets \
    $$PWD/features \

HEADERS += \
    $$PWD/atm_widgets/*.h \
    $$PWD/features/*.h \

SOURCES += \
    $$PWD/atm_widgets/*.cpp \
    $$PWD/features/*.cpp \

FORMS += \
    $$PWD/atm_widgets/*.ui \

RESOURCES += \
    atm_resources.qrc










