QT += gui core widgets

TEMPLATE = app
TARGET = src
CONFIG += console c++11

QMAKE_CXX = ccache g++

DEPENDPATH += \
    ../lib_console/messengers \
    ../lib_console/output_configuration \
    ../lib_gui \
    ../atm_core/credit_department \

INCLUDEPATH += \
    ../lib_console/messengers \
    ../lib_console/output_configuration \
    ../lib_gui \
    ../atm_core/credit_department \
    $$PWD/atm_operations \
    $$PWD/atm_operations/credit_operations \
    $$PWD/user_data \
    $$PWD/input \
    $$PWD/application_management \
    $$PWD/interface_management \

HEADERS += \
    $$PWD/atm_operations/*.h \
    $$PWD/atm_operations/credit_operations/*.h \
    $$PWD/user_data/*.h \
    $$PWD/input/*.h \
    $$PWD/interface_management/*.h \

SOURCES += \
    $$PWD/atm_operations/*.cpp \
    $$PWD/atm_operations/credit_operations/*.cpp \
    $$PWD/user_data/*.cpp \
    $$PWD/input/*.cpp \
    $$PWD/interface_management/*.cpp \

LIBS += \
    -L$$OUT_PWD/../lib_console -llib_console \
    -L$$OUT_PWD/../lib_gui -llib_gui \
    -L$$OUT_PWD/../atm_core -latm_core \
