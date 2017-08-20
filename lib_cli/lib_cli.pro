TEMPLATE = lib
TARGET = lib_cli
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang++

INCLUDEPATH += \
    $$PWD/messengers/registration_messengers \
    $$PWD/view_model/registration \
    $$PWD/output_configuration \
    $$PWD/user_input_handling \
    $$PWD/messengers \
    $$PWD/view_model \

HEADERS += \
    $$PWD/messengers/registration_messengers/*.h \
    $$PWD/view_model/registration/*.h \
    $$PWD/output_configuration/*.h \
    $$PWD/user_input_handling/*.h \
    $$PWD/messengers/*.h \
    $$PWD/view_model/*.h \

SOURCES += \
    $$PWD/messengers/registration_messengers/*.cpp \
    $$PWD/view_model/registration/*.cpp \
    $$PWD/output_configuration/*.cpp \
    $$PWD/user_input_handling/*.cpp \
    $$PWD/messengers/*.cpp \
    $$PWD/view_model/*cpp \



