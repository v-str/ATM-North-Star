TEMPLATE = subdirs
TARGET = ATM-North-Star

QMAKE_CXX = ccache clang++

SUBDIRS += \
    atm_model \
    lib_cli \
    lib_gui \
    atm_app \

atm_model.depends = lib_cli lib_gui atm_app

DISTFILES += \
    ToDo_List





