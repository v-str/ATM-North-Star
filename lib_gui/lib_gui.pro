QT += widgets

TEMPLATE = lib
TARGET = lib_gui
CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache g++

INCLUDEPATH += \

HEADERS += \
    $$PWD/*.h

SOURCES += \
    $$PWD/*.cpp

FORMS += \
    $$PWD/*.ui
