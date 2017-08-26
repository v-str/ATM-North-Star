TEMPLATE = lib
TARGET = lib_cli
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang++

INCLUDEPATH += \
    $$PWD/messengers/registration_messengers/confirmation_animation \
    $$PWD/messengers/registration_messengers \
    $$PWD/output_configuration \
    $$PWD/user_input_handling \
    $$PWD/messengers \
    $$PWD/view_model \

HEADERS += \
    $$PWD/messengers/registration_messengers/confirmation_animation/*.h \
    $$PWD/messengers/registration_messengers/*.h \
    $$PWD/output_configuration/*.h \
    $$PWD/user_input_handling/*.h \
    $$PWD/messengers/*.h \
    $$PWD/view_model/*.h \

SOURCES += \
    $$PWD/messengers/registration_messengers/confirmation_animation/*.cpp \
    $$PWD/messengers/registration_messengers/*.cpp \
    $$PWD/output_configuration/*.cpp \
    $$PWD/user_input_handling/*.cpp \
    $$PWD/messengers/*.cpp \
    $$PWD/view_model/*cpp \

