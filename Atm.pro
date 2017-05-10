TEMPLATE = subdirs
TARGET = Atm

QMAKE_CXX = ccache clang

SUBDIRS += \
    application \
    lib_console \
    lib_gui \
    atm_core \

application.depends = lib_console lib_gui atm_core

DISTFILES += \
    ToDo_List





