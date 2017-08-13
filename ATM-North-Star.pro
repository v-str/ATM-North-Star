TEMPLATE = subdirs
TARGET = ATM-North-Star

QMAKE_CXX = ccache clang++

SUBDIRS += \
    application \
    lib_cli \
    lib_gui \
    lib_atm_model \

application.depends = lib_cli lib_gui lib_atm_model

DISTFILES += \
    ToDo_List





