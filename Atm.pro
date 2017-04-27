TEMPLATE = subdirs
TARGET = Atm

QMAKE_CXX = ccache g++

SUBDIRS += \
    src \
    lib_console \
    lib_gui \
    atm_core \

src.depends = lib_console lib_gui atm_core

DISTFILES += \
    ToDo_List





