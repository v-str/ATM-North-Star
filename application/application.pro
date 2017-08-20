QT += gui core widgets

TEMPLATE = app
TARGET = application
CONFIG += console c++11

QMAKE_CXX = ccache clang++

DEPENDPATH += \
    ../lib_gui/widgets_arrangement/common/modificators/primitive \
    ../lib_gui/widgets_arrangement/common/modificators/composite \
    ../lib_gui/widgets_arrangement/common/widgets_geometries \
    ../lib_cli/messengers/registration_messengers \
    ../lib_gui/widgets_arrangement/splash_screen \
    ../lib_atm_model/incoming_data_handling \
    ../lib_cli/output_configuration \
    ../lib_cli/user_input_handling \
    ../lib_gui/widgets_appearance \
    ../lib_gui/features/animation \
    ../lib_gui/features/service \
    ../lib_gui/atm_widgets \
    ../lib_atm_model/interaction \
    ../lib_cli/view_model \
    ../lib_cli/view_model/registration \
    ../lib_cli/messengers \

INCLUDEPATH += \
    ../lib_gui/widgets_arrangement/common/modificators/primitive \
    ../lib_gui/widgets_arrangement/common/modificators/composite \
    ../lib_gui/widgets_arrangement/common/widgets_geometries \
    ../lib_cli/messengers/registration_messengers \
    ../lib_gui/widgets_arrangement/splash_screen \
    ../lib_atm_model/incoming_data_handling \
    ../lib_cli/output_configuration \
    ../lib_cli/user_input_handling \
    ../lib_gui/widgets_appearance \
    ../lib_gui/features/animation \
    ../lib_gui/features/service \
    ../lib_atm_model/interaction \
    ../lib_gui/atm_widgets \
    ../lib_cli/view_model \
    ../lib_cli/view_model/registration \
    ../lib_cli/messengers \
    ../lib_gui/features \
    $$PWD/atm_operations/credit_operations \ #deprecated code, should be removed
    $$PWD/interface_presenter \
    $$PWD/interface_presenter/console_presenter \
    $$PWD/application_launch \
    $$PWD/atm_operations \ #deprecated code, should be removed
    $$PWD/user_data \ #deprecated code, should be removed

HEADERS += \
    $$PWD/atm_operations/credit_operations/*.h \
    $$PWD/interface_presenter/*.h \
    $$PWD/interface_presenter/console_presenter/*.h \
    $$PWD/application_launch/*.h \
    $$PWD/atm_operations/*.h \
    $$PWD/user_data/*.h \

SOURCES += \
    $$PWD/atm_operations/credit_operations/*.cpp \
    $$PWD/interface_presenter/*.cpp \
    $$PWD/interface_presenter/console_presenter/*.cpp \
    $$PWD/application_launch/*.cpp \
    $$PWD/atm_operations/*.cpp \
    $$PWD/user_data/*.cpp \

LIBS += \
    -L$$OUT_PWD/../lib_cli -llib_cli \
    -L$$OUT_PWD/../lib_gui -llib_gui \
    -L$$OUT_PWD/../lib_atm_model -llib_atm_model \

