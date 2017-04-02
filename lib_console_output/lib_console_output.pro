TEMPLATE = lib
TARGET = lib_console_output
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

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
    $$PWD/messengers \
    $$PWD/output_configuration \

HEADERS += \
    $$PWD/messengers/*.h \
    $$PWD/output_configuration/*.h \

SOURCES += \
    $$PWD/messengers/*.cpp \
    $$PWD/output_configuration/*.cpp \


