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
    ../lib_atm/interaction \
    ../lib_cli/messengers \

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
    ../lib_atm/interaction \
    ../lib_gui/atm_widgets \
    ../lib_cli/messengers \
    ../lib_gui/features \
    $$PWD/cli_presenter/transaction_menu \
    $$PWD/atm_operations/credit_operations \ #deprecated code, should be removed
    $$PWD/cli_presenter/authentication \
    $$PWD/cli_presenter/initial_menu \
    $$PWD/application_launch \
    $$PWD/gui_presenter \
    $$PWD/atm_operations \ #deprecated code, should be removed
    $$PWD/user_data \ #deprecated code, should be removed

HEADERS += \
    $$PWD/cli_presenter/transaction_menu/*.h \
    $$PWD/atm_operations/credit_operations/*.h \
    $$PWD/cli_presenter/authentication/*.h \
    $$PWD/cli_presenter/initial_menu/*.h \
    $$PWD/application_launch/*.h \
    $$PWD/gui_presenter/*.h \
    $$PWD/atm_operations/*.h \
    $$PWD/user_data/*.h \

SOURCES += \
    $$PWD/atm_operations/credit_operations/*.cpp \
    $$PWD/cli_presenter/transaction_menu/*.cpp \
    $$PWD/cli_presenter/authentication/*.cpp \
    $$PWD/cli_presenter/initial_menu/*.cpp \
    $$PWD/application_launch/*.cpp \
    $$PWD/gui_presenter/*.cpp \
    $$PWD/atm_operations/*.cpp \
    $$PWD/user_data/*.cpp \

LIBS += \
    -L$$OUT_PWD/../lib_cli -llib_cli \
    -L$$OUT_PWD/../lib_gui -llib_gui \
    -L$$OUT_PWD/../lib_atm -llib_atm \

