QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
TARGET = lib_gui

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang++

DEPENDPATH += \
    ../widgets_arrangement/common/modificators/primitive \
    ../widgets_arrangement/common/modificators/composite \
    ../widgets_arrangement/common/widgets_geometries/ \
    ../widgets_arrangement/splash_screen \
    ../widgets_appearance \
    ../operation_frames \
    ../atm_widgets \
    ../subwidgets \
    ../features \
    ../images \
    ../sounds \

INCLUDEPATH += \
    $$PWD/widgets_arrangement/common/modificators/primitive \
    $$PWD/widgets_arrangement/common/modificators/composite \
    $$PWD/widgets_arrangement/common/widgets_geometries \
    $$PWD/widgets_arrangement/splash_screen \
    $$PWD/widgets_appearance \
    $$PWD/operation_frames \
    $$PWD/atm_widgets \
    $$PWD/subwidgets \
    $$PWD/features \

HEADERS += \
    $$PWD/widgets_arrangement/common/modificators/primitive/*.h \
    $$PWD/widgets_arrangement/common/modificators/composite/*.h \
    $$PWD/widgets_arrangement/common/widgets_geometries/*.h \
    $$PWD/widgets_arrangement/splash_screen/*.h \
    $$PWD/widgets_appearance/*.h \
    $$PWD/operation_frames/*.h \
    $$PWD/atm_widgets/*.h \
    $$PWD/subwidgets/*.h \
    $$PWD/features/*.h \

SOURCES += \
    $$PWD/widgets_arrangement/common/modificators/primitive/*.cpp \
    $$PWD/widgets_arrangement/common/modificators/composite/*.cpp \
    $$PWD/widgets_arrangement/common/widgets_geometries/*.cpp \
    $$PWD/widgets_arrangement/splash_screen/*.cpp \
    $$PWD/widgets_appearance/*.cpp \
    $$PWD/operation_frames/*.cpp \
    $$PWD/atm_widgets/*.cpp \
    $$PWD/subwidgets/*.cpp \
    $$PWD/features/*.cpp \

FORMS += \
    $$PWD/atm_widgets/*.ui

RESOURCES += \
    atm_resources.qrc










