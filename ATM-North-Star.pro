TEMPLATE = subdirs
TARGET = ATM-North-Star

QMAKE_CXX = ccache clang++

SUBDIRS += \
    atm_model \
    lib_atm_presenter \
    lib_cli \
    lib_gui \
    lib_atm \

atm_model.depends = lib_atm_presenter lib_cli lib_gui lib_atm

DISTFILES += \
    ToDo_List





