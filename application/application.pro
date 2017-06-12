QT += gui core widgets

TEMPLATE = app
TARGET = application
CONFIG += console c++11

QMAKE_CXX = ccache clang++

DEPENDPATH += \
    ../lib_console/messengers \
    ../lib_console/output_configuration \
    ../lib_gui/widgets_appearance \
    ../lib_gui/widgets_arrangement \
    ../lib_gui/atm_widgets \
    ../lib_gui/features \
    ../atm/atm_machine \
    ../atm/incoming_data_processing \

INCLUDEPATH += \
    ../lib_console/messengers \
    ../lib_console/output_configuration \
    ../lib_gui/widgets_appearance \
    ../lib_gui/widgets_arrangement \
    ../lib_gui/atm_widgets \
    ../lib_gui/features \
    ../atm/atm_machine \
    ../atm/incoming_data_processing \
    $$PWD/atm_operations \ #deprecated code, should be removed
    $$PWD/atm_operations/credit_operations \ #deprecated code, should be removed
    $$PWD/user_data \ #deprecated code, should be removed
    $$PWD/mode_integration \
    $$PWD/console_version/initial_menu \
    $$PWD/console_version/transaction_menu \
    $$PWD/console_version/authentication \
    $$PWD/console_version/user_input_handling \
    $$PWD/graphical_version \

HEADERS += \
    $$PWD/atm_operations/*.h \
    $$PWD/atm_operations/credit_operations/*.h \
    $$PWD/user_data/*.h \
    $$PWD/mode_integration/*.h \
    $$PWD/console_version/initial_menu/*.h \
    $$PWD/console_version/transaction_menu/*.h \
    $$PWD/console_version/authentication/*.h \
    $$PWD/console_version/user_input_handling/*.h \
    $$PWD/graphical_version/*.h \

SOURCES += \
    $$PWD/atm_operations/*.cpp \
    $$PWD/atm_operations/credit_operations/*.cpp \
    $$PWD/user_data/*.cpp \
    $$PWD/mode_integration/*.cpp \
    $$PWD/console_version/initial_menu/*.cpp \
    $$PWD/console_version/transaction_menu/*.cpp \
    $$PWD/console_version/authentication/*.cpp \
    $$PWD/console_version/user_input_handling/*.cpp \
    $$PWD/graphical_version/*.cpp \

LIBS += \
    -L$$OUT_PWD/../lib_console -llib_console \
    -L$$OUT_PWD/../lib_gui -llib_gui \
    -L$$OUT_PWD/../atm -latm \

