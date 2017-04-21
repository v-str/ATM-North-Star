QT += gui core widgets

TEMPLATE = app
TARGET = src
CONFIG += console c++11

QMAKE_CXX = ccache g++

DEPENDPATH += \
    ../lib_console_output/messengers \
    ../lib_console_output/output_configuration \
    ../lib_gui \

INCLUDEPATH += \
    ../lib_console_output/messengers \
    ../lib_console_output/output_configuration \
    ../lib_gui \
    $$PWD/atm_operations \
    $$PWD/atm_operations \
    $$PWD/atm_operations/credit_operations \
    $$PWD/user_data \
    $$PWD/input \
    $$PWD/application_management \

HEADERS += \
    $$PWD/atm_operations/*.h \
    $$PWD/atm_operations/credit_operations/*.h \
    $$PWD/user_data/*.h \
    $$PWD/input/*.h \
    $$PWD/application_management/*.h \

SOURCES += \
    $$PWD/application/*.cpp \
    $$PWD/atm_operations/*.cpp \
    $$PWD/atm_operations/credit_operations/*.cpp \
    $$PWD/user_data/*.cpp \
    $$PWD/input/*.cpp \
    $$PWD/application_management/*.cpp \

LIBS += \
    -L$$OUT_PWD/../lib_console_output -llib_console_output \
    -L$$OUT_PWD/../lib_gui -llib_gui


