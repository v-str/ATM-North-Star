TEMPLATE = app
CONFIG += console c++11
CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11

CONFIG -= app_bundle \
    qt

INCLUDEPATH += \
    ../lib_console_output/messengers \
    ../lib_console_output/output_configuration \
    ../src/application \
    ../src/atm_operations \
    ../src/user_data \
    ../src/input \

HEADERS += \
    $$PWD/application/*.h \
    $$PWD/atm_operations/*.h \
    $$PWD/user_data/*.h \
    $$PWD/input/*.h \
    atm_operations/operation_selector.h

SOURCES += \
    $$PWD/application/*.cpp \
    $$PWD/atm_operations/*.cpp \
    $$PWD/user_data/*.cpp \
    $$PWD/input/*.cpp \
    atm_operations/operation_selector.cpp



LIBS += -L../lib_console_output -llib_console_output


