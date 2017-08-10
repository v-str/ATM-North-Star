QT += gui core widgets

TEMPLATE = app
TARGET = application
CONFIG += console c++11

QMAKE_CXX = ccache clang++

DEPENDPATH += \
    ../lib_gui/widgets_arrangement/common/modificators/primitive \
    ../lib_gui/widgets_arrangement/common/modificators/composite \
    ../lib_gui/widgets_arrangement/common/widgets_geometries \
    ../lib_gui/widgets_arrangement/splash_screen \
    ../lib_atm/incoming_data_processing \
    ../lib_cli/output_configuration \
    ../lib_cli/user_input_handling \
    ../lib_gui/widgets_appearance \
    ../lib_gui/features/animation \
    ../lib_gui/features/service \
    ../lib_gui/atm_widgets \
    ../lib_atm/atm_machine \
    ../lib_cli/messengers \
    ../lib_atm_presenter \

INCLUDEPATH += \
    ../lib_gui/widgets_arrangement/common/modificators/primitive \
    ../lib_gui/widgets_arrangement/common/modificators/composite \
    ../lib_gui/widgets_arrangement/common/widgets_geometries \
    ../lib_gui/widgets_arrangement/splash_screen \
    ../lib_atm/incoming_data_processing \
    ../lib_cli/output_configuration \
    ../lib_cli/user_input_handling \
    ../lib_gui/widgets_appearance \
    ../lib_gui/features/animation \
    ../lib_gui/features/service \
    ../lib_atm/atm_machine \
    ../lib_gui/atm_widgets \
    ../lib_cli/messengers \
    ../lib_gui/features \
    ../lib_atm_presenter \
    $$PWD/console_version/transaction_menu \
    $$PWD/atm_operations/credit_operations \ #deprecated code, should be removed
    $$PWD/console_version/authentication \
    $$PWD/console_version/initial_menu \
    $$PWD/application_launch \
    $$PWD/graphical_version \
    $$PWD/atm_operations \ #deprecated code, should be removed
    $$PWD/user_data \ #deprecated code, should be removed

HEADERS += \
    $$PWD/console_version/transaction_menu/*.h \
    $$PWD/atm_operations/credit_operations/*.h \
    $$PWD/console_version/authentication/*.h \
    $$PWD/console_version/initial_menu/*.h \
    $$PWD/application_launch/*.h \
    $$PWD/graphical_version/*.h \
    $$PWD/atm_operations/*.h \
    $$PWD/user_data/*.h \

SOURCES += \
    $$PWD/atm_operations/credit_operations/*.cpp \
    $$PWD/console_version/transaction_menu/*.cpp \
    $$PWD/console_version/authentication/*.cpp \
    $$PWD/console_version/initial_menu/*.cpp \
    $$PWD/application_launch/*.cpp \
    $$PWD/graphical_version/*.cpp \
    $$PWD/atm_operations/*.cpp \
    $$PWD/user_data/*.cpp \

LIBS += \
    -L$$OUT_PWD/../lib_cli -llib_cli \
    -L$$OUT_PWD/../lib_gui -llib_gui \
    -L$$OUT_PWD/../lib_atm -llib_atm \
    -L$$OUT_PWD/../lib_atm_presenter -llib_atm_presenter \

