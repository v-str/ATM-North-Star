TEMPLATE = subdirs
TARGET = Atm

QMAKE_CXX = ccache g++

SUBDIRS += \
    src \
    lib_console \
    lib_gui \

src.depends = lib_console lib_gui

DISTFILES += \
    ToDo_List





