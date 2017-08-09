TEMPLATE = lib
TARGET = lib_cli
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang++

INCLUDEPATH += \
    $$PWD/user_input_handling \
    $$PWD/output_configuration \
    $$PWD/messengers \

HEADERS += \
    $$PWD/user_input_handling/*.h \
    $$PWD/output_configuration/*.h \
    $$PWD/messengers/*.h \

SOURCES += \
    $$PWD/user_input_handling/*.cpp \
    $$PWD/output_configuration/*.cpp \
    $$PWD/messengers/*.cpp \



