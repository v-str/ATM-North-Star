TEMPLATE = subdirs
TARGET = Atm

#QMAKE_CXX = ccache g++
#QMAKE_CXX = ccache clang++

QMAKE_CXXFLAGS += \
    -Wall \
    -Wextra \
    -Wshadow \
    -Wnon-virtual-dtor \
    -pedantic \
    -Weverything \
    -Wno-c++98-compat \
    -Wno-c++98-compat-pedantic

SUBDIRS += \
    src \
    lib_console_output \
    lib_gui \

src.depends = lib_console_output lib_gui

DISTFILES += \
    ToDo_List





