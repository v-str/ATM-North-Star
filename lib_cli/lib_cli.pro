TEMPLATE = lib
TARGET = lib_cli
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang++

INCLUDEPATH += \
    $$PWD/output_configuration \
    $$PWD/messengers \

HEADERS += \
    $$PWD/output_configuration/*.h \
    $$PWD/messengers/*.h \

SOURCES += \
    $$PWD/output_configuration/*.cpp \
    $$PWD/messengers/*.cpp \



