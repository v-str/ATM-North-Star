TEMPLATE = subdirs
TARGET = ATM-North-Star

QMAKE_CXX = ccache clang++

SUBDIRS += \
    application \
    lib_console \
    lib_gui \
    atm \

application.depends = lib_console lib_gui atm

DISTFILES += \
    ToDo_List





