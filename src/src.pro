TEMPLATE = app
TARGET = app
CONFIG += console c++11

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

CONFIG -= app_bundle \
    qt

DEPENDPATH += \
    ../lib_console_output

INCLUDEPATH += \
    ../lib_console_output/messengers \
    ../lib_console_output/output_configuration \
    $$PWD/application \
    $$PWD/atm_operations \
    $$PWD/user_data \
    $$PWD/input \
    $$PWD/application_management \

HEADERS += \
    $$PWD/application/*.h \
    $$PWD/atm_operations/*.h \
    $$PWD/user_data/*.h \
    $$PWD/input/*.h \
    $$PWD/application_management/*.h \

SOURCES += \
    $$PWD/application/*.cpp \
    $$PWD/atm_operations/*.cpp \
    $$PWD/user_data/*.cpp \
    $$PWD/input/*.cpp \
    $$PWD/application_management/*.cpp \

LIBS += -L../lib_console_output/ -llib_console_output

