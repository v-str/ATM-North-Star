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
    ../lib_cli/output_configuration \
    ../atm/incoming_data_processing \
    ../lib_gui/widgets_appearance \
    ../lib_gui/features/animation \
    ../lib_gui/features/service \
    ../lib_cli/messengers \
    ../lib_gui/atm_widgets \
    ../atm/atm_machine \

INCLUDEPATH += \
    ../lib_gui/widgets_arrangement/common/modificators/primitive \
    ../lib_gui/widgets_arrangement/common/modificators/composite \
    ../lib_gui/widgets_arrangement/common/widgets_geometries \
    ../lib_gui/widgets_arrangement/splash_screen \
    ../lib_cli/output_configuration \
    ../atm/incoming_data_processing \
    ../lib_gui/widgets_appearance \
    ../lib_gui/features/animation \
    ../lib_gui/features/service \
    ../lib_cli/messengers \
    ../lib_gui/atm_widgets \
    ../lib_gui/features \
    ../atm/atm_machine \
    $$PWD/console_version/user_input_handling \
    $$PWD/console_version/transaction_menu \
    $$PWD/atm_operations/credit_operations \ #deprecated code, should be removed
    $$PWD/console_version/authentication \
    $$PWD/console_version/initial_menu \
    $$PWD/graphical_version \
    $$PWD/mode_integration \
    $$PWD/atm_operations \ #deprecated code, should be removed
    $$PWD/user_data \ #deprecated code, should be removed

HEADERS += \
    $$PWD/console_version/user_input_handling/*.h \
    $$PWD/console_version/transaction_menu/*.h \
    $$PWD/atm_operations/credit_operations/*.h \
    $$PWD/console_version/authentication/*.h \
    $$PWD/console_version/initial_menu/*.h \
    $$PWD/graphical_version/*.h \
    $$PWD/mode_integration/*.h \
    $$PWD/atm_operations/*.h \
    $$PWD/user_data/*.h \

SOURCES += \
    $$PWD/console_version/user_input_handling/*.cpp \
    $$PWD/atm_operations/credit_operations/*.cpp \
    $$PWD/console_version/transaction_menu/*.cpp \
    $$PWD/console_version/authentication/*.cpp \
    $$PWD/console_version/initial_menu/*.cpp \
    $$PWD/graphical_version/*.cpp \
    $$PWD/mode_integration/*.cpp \
    $$PWD/atm_operations/*.cpp \
    $$PWD/user_data/*.cpp \

LIBS += \
    -L$$OUT_PWD/../lib_cli -llib_cli \
    -L$$OUT_PWD/../lib_gui -llib_gui \
    -L$$OUT_PWD/../atm -latm \

