TEMPLATE = lib
TARGET = lib_gui
CONFIG = GUI

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

INCLUDEPATH += \


HEADERS += \


SOURCES += \
