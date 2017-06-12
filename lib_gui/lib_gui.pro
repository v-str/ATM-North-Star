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
    ../widgets_arrangement \
    ../widgets_arrangement/font_settings \
    ../features \
    ../images \

INCLUDEPATH += \
    $$PWD/atm_widgets \
    $$PWD/widgets_appearance \
    $$PWD/widgets_arrangement \
    $$PWD/widgets_arrangement/font_settings \
    $$PWD/features \

HEADERS += \
    $$PWD/atm_widgets/*.h \
    $$PWD/widgets_appearance/*.h \
    $$PWD/widgets_arrangement/*.h \
    $$PWD/widgets_arrangement/font_settings/*.h \
    $$PWD/features/*.h \

SOURCES += \
    $$PWD/atm_widgets/*.cpp \
    $$PWD/widgets_appearance/*.cpp \
    $$PWD/widgets_arrangement/*.cpp \
    $$PWD/widgets_arrangement/font_settings/*.cpp \
    $$PWD/features/*.cpp \

FORMS += \
    $$PWD/atm_widgets/*.ui \

RESOURCES += \
    atm_resources.qrc










