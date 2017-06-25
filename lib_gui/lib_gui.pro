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
    ../widgets_appearance \
    ../operation_frames \
    ../widgets_arrangement \
    ../features \
    ../images \
    ../sounds \

INCLUDEPATH += \
    $$PWD/atm_widgets \
    $$PWD/widgets_appearance \
    $$PWD/operation_frames \
    $$PWD/widgets_arrangement \
    $$PWD/features \

HEADERS += \
    $$PWD/atm_widgets/*.h \
    $$PWD/widgets_appearance/*.h \
    $$PWD/operation_frames/*.h \
    $$PWD/widgets_arrangement/*.h \
    $$PWD/features/*.h \

SOURCES += \
    $$PWD/atm_widgets/*.cpp \
    $$PWD/widgets_appearance/*.cpp \
    $$PWD/operation_frames/*.cpp \
    $$PWD/widgets_arrangement/*.cpp \
    $$PWD/features/*.cpp \

FORMS += \
    $$PWD/atm_widgets/*.ui

RESOURCES += \
    atm_resources.qrc










