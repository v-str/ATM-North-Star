TEMPLATE = subdirs
TARGET = ATM-North-Star

QMAKE_CXX = ccache clang++

SUBDIRS += \
    atm_model \
    lib_cli \
    lib_gui \
    lib_atm \

atm_model.depends = lib_cli lib_gui lib_atm

DISTFILES += \
    ToDo_List





