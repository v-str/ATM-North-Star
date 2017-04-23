QT += widgets

TEMPLATE = lib
TARGET = lib_gui
CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache g++

DEPENDPATH += \
    ../initial_form \

INCLUDEPATH += \
    $$PWD/initial_form \

HEADERS += \
    $$PWD/initial_form/*.h \

SOURCES += \
    $$PWD/initial_form/*.cpp \

FORMS += \
    $$PWD/initial_form/*.ui \



