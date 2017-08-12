QT += gui core widgets

TEMPLATE = app
TARGET = presenter
CONFIG += console c++11

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang++

DEPENDPATH += \
    ../lib_gui/widgets_arrangement/common/modificators/primitive \
    ../lib_gui/widgets_arrangement/common/modificators/composite \
    ../lib_gui/widgets_arrangement/common/widgets_geometries \
    ../lib_gui/widgets_arrangement/splash_screen \
    ../lib_cli/output_configuration \
    ../lib_cli/user_input_handling \
    ../lib_gui/widgets_appearance \
    ../lib_gui/features/animation \
    ../lib_gui/features/service \
    ../lib_gui/atm_widgets \
    ../lib_cli/messengers \

INCLUDEPATH += \
    ../lib_gui/widgets_arrangement/common/modificators/primitive \
    ../lib_gui/widgets_arrangement/common/modificators/composite \
    ../lib_gui/widgets_arrangement/common/widgets_geometries \
    ../lib_gui/widgets_arrangement/splash_screen \
    ../lib_cli/output_configuration \
    ../lib_cli/user_input_handling \
    ../lib_gui/widgets_appearance \
    ../lib_gui/features/animation \
    ../lib_gui/features/service \
    ../lib_gui/atm_widgets \
    ../lib_cli/messengers \
    ../lib_gui/features \
    $$PWD/application_launch \

HEADERS += \
    $$PWD/application_launch/*.h \

SOURCES += \
    $$PWD/application_launch/*.cpp \

#LIBS += \
#    -L$$OUT_PWD/../lib_cli -llib_cli \
#    -L$$OUT_PWD/../lib_gui -llib_gui \

