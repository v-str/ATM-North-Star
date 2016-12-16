TARGET = Atm

TEMPLATE = app

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11

CONFIG -= app_bundle \
    qt

INCLUDEPATH += \
    src \
    src/Application \
    src/Console_core \
    src/Console_user_data \
    src/Console_output/Messengers \
    src/Console_output/Output_configuration \
    src/Console_input

DISTFILES += \
    ToDo_List

HEADERS += \
    $$PWD/src/Application/*.h \
    $$PWD/src/Console_core/*.h \
    $$PWD/src/Console_user_data/*.h \
    $$PWD/src/Console_output/Messengers/*.h \
    $$PWD/src/Console_output/Output_configuration/*.h \
    $$PWD/src/Console_input/*.h \
    src/Console_user_data/atm_user.h


SOURCES += \
    $$PWD/src/Application/*.cpp \
    $$PWD/src/Console_core/*.cpp \
    $$PWD/src/Console_user_data/*.cpp \
    $$PWD/src/Console_output/Messengers/*.cpp \
    $$PWD/src/Console_output/Output_configuration/*.cpp \
    $$PWD/src/Console_input/*.cpp \
    src/Console_user_data/atm_user.cpp





