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
    ../operation_widgets/registration_menu \
    ../widgets_arrangement/splash_screen \
    ../operation_widgets/initial_menu \
    ../operation_widgets/login_menu \
    ../operation_widgets/demo_menu \
    ../widgets_appearance \
    ../features/animation \
    ../features/service \
    ../atm_widgets \
    ../subwidgets \
    ../images \
    ../sounds \

INCLUDEPATH += \
    $$PWD/widgets_arrangement/common/modificators/primitive \
    $$PWD/widgets_arrangement/common/modificators/composite \
    $$PWD/widgets_arrangement/common/widgets_geometries \
    $$PWD/operation_widgets/registration_menu \
    $$PWD/widgets_arrangement/splash_screen \
    $$PWD/operation_widgets/initial_menu \
    $$PWD/operation_widgets/login_menu \
    $$PWD/operation_widgets/demo_menu \
    $$PWD/widgets_appearance \
    $$PWD/features/animation \
    $$PWD/features/service \
    $$PWD/atm_widgets \
    $$PWD/subwidgets \

HEADERS += \
    $$PWD/widgets_arrangement/common/modificators/primitive/*.h \
    $$PWD/widgets_arrangement/common/modificators/composite/*.h \
    $$PWD/widgets_arrangement/common/widgets_geometries/*.h \
    $$PWD/operation_widgets/registration_menu/*.h \
    $$PWD/widgets_arrangement/splash_screen/*.h \
    $$PWD/operation_widgets/initial_menu/*.h \
    $$PWD/operation_widgets/login_menu/*.h \
    $$PWD/operation_widgets/demo_menu/*.h \
    $$PWD/widgets_appearance/*.h \
    $$PWD/features/animation/*.h \
    $$PWD/features/service/*.h \
    $$PWD/atm_widgets/*.h \
    $$PWD/subwidgets/*.h \

SOURCES += \
    $$PWD/widgets_arrangement/common/modificators/primitive/*.cpp \
    $$PWD/widgets_arrangement/common/modificators/composite/*.cpp \
    $$PWD/widgets_arrangement/common/widgets_geometries/*.cpp \
    $$PWD/operation_widgets/registration_menu/*.cpp \
    $$PWD/widgets_arrangement/splash_screen/*.cpp \
    $$PWD/operation_widgets/initial_menu/*.cpp \
    $$PWD/operation_widgets/login_menu/*.cpp \
    $$PWD/operation_widgets/demo_menu/*.cpp \
    $$PWD/widgets_appearance/*.cpp \
    $$PWD/features/animation/*.cpp \
    $$PWD/features/service/*.cpp \
    $$PWD/atm_widgets/*.cpp \
    $$PWD/subwidgets/*.cpp \

FORMS += \
    $$PWD/atm_widgets/*.ui

RESOURCES += \
    atm_resources.qrc










