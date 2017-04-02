TEMPLATE = subdirs
TARGET = Atm

QMAKE_CXX = ccache clang++

SUBDIRS += \
    src \
    lib_console_output \
    lib_gui \

src.depends = lib_console_output lib_gui

DISTFILES += \
    ToDo_List





