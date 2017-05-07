QT += gui core widgets

TEMPLATE = app
TARGET = application
CONFIG += console c++11

QMAKE_CXX = ccache g++

DEPENDPATH += \
    ../lib_console/messengers \
    ../lib_console/output_configuration \
    ../lib_gui/atm_splash_screen \
    ../atm_core/credit_department \
    ../console_mode \
    ../gui_mode \

INCLUDEPATH += \
    ../lib_console/messengers \
    ../lib_console/output_configuration \
    ../lib_gui/atm_splash_screen \
    ../atm_core/credit_department \
    $$PWD/atm_operations \ #deprecated code, should be remade
    $$PWD/atm_operations/credit_operations \ #deprecated code, should be remade
    $$PWD/user_data \ #deprecated code, should be remade
    $$PWD/input \ #deprecated code, should be remade
    $$PWD/application_management \ #deprecated code, should be remade
    $$PWD/mode_selection \

HEADERS += \
    $$PWD/atm_operations/*.h \
    $$PWD/atm_operations/credit_operations/*.h \
    $$PWD/user_data/*.h \
    $$PWD/input/*.h \
    $$PWD/mode_selection/*.h \

SOURCES += \
    $$PWD/atm_operations/*.cpp \
    $$PWD/atm_operations/credit_operations/*.cpp \
    $$PWD/user_data/*.cpp \
    $$PWD/input/*.cpp \
    $$PWD/mode_selection/*.cpp \

LIBS += \
    -L$$OUT_PWD/../lib_console -llib_console \
    -L$$OUT_PWD/../lib_gui -llib_gui \
    -L$$OUT_PWD/../atm_core -latm_core \
