TEMPLATE = subdirs
TARGET = Atm

QMAKE_CXX = ccache g++

SUBDIRS += \
    application \
    lib_console \
    lib_gui \
    atm_core \

application.depends = lib_console lib_gui atm_core

DISTFILES += \
    ToDo_List





