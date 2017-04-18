QT += core gui widgets

TEMPLATE = subdirs
TARGET = Atm

QMAKE_CXX = ccache g++

SUBDIRS += \
    src \
    lib_console_output \
    lib_gui \

src.depends = lib_console_output lib_gui

DISTFILES += \
    ToDo_List





