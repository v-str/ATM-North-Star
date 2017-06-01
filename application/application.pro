QT += gui core widgets

TEMPLATE = app
TARGET = application
CONFIG += console c++11

QMAKE_CXX = ccache clang++

DEPENDPATH += \
    ../lib_console/messengers \
    ../lib_console/output_configuration \
    ../lib_gui/atm_splash_screen \
    ../atm/atm_machine \
    ../atm/incoming_data_processing \

INCLUDEPATH += \
    ../lib_console/messengers \
    ../lib_console/output_configuration \
    ../lib_gui/atm_splash_screen \
    ../atm/atm_machine \
    ../atm/incoming_data_processing \
    $$PWD/atm_operations \ #deprecated code, should be removed
    $$PWD/atm_operations/credit_operations \ #deprecated code, should be removed
    $$PWD/user_data \ #deprecated code, should be removed
    $$PWD/mode_merging \
    $$PWD/console_version/initial_menu \
    $$PWD/console_version/transaction_menu \
    $$PWD/console_version/authentication \
    $$PWD/console_version/user_input_handling \
    $$PWD/gui_mode \

HEADERS += \
    $$PWD/atm_operations/*.h \
    $$PWD/atm_operations/credit_operations/*.h \
    $$PWD/user_data/*.h \
    $$PWD/mode_merging/*.h \
    $$PWD/console_version/initial_menu/*.h \
    $$PWD/console_version/transaction_menu/*.h \
    $$PWD/console_version/authentication/*.h \
    $$PWD/console_version/user_input_handling/*.h \
    $$PWD/gui_mode/*.h \

SOURCES += \
    $$PWD/atm_operations/*.cpp \
    $$PWD/atm_operations/credit_operations/*.cpp \
    $$PWD/user_data/*.cpp \
    $$PWD/mode_merging/*.cpp \
    $$PWD/console_version/initial_menu/*.cpp \
    $$PWD/console_version/transaction_menu/*.cpp \
    $$PWD/console_version/authentication/*.cpp \
    $$PWD/console_version/user_input_handling/*.cpp \
    $$PWD/gui_mode/*.cpp \

LIBS += \
    -L$$OUT_PWD/../lib_console -llib_console \
    -L$$OUT_PWD/../lib_gui -llib_gui \
    -L$$OUT_PWD/../atm -latm \
