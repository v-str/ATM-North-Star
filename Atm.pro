TARGET = Atm

TEMPLATE = app

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11

CONFIG -= app_bundle \
    qt

INCLUDEPATH += \
    src \
    src/Application \
    src/Console_core \
    src/Console_user_data_processing \
    src/Console_output_processing/Messengers \
    src/Console_output_processing/Output_configuration \
    src/Console_input_processing

DISTFILES += \
    ToDo_List

HEADERS += \
    $$PWD/src/Application/*.h \
    $$PWD/src/Console_core/*.h \
    $$PWD/src/Console_user_data_processing/*.h \
    $$PWD/src/Console_output_processing/Messengers/*.h \
    $$PWD/src/Console_output_processing/Output_configuration/*.h \
    $$PWD/src/Console_input_processing/*.h \


SOURCES += \
    $$PWD/src/Application/*.cpp \
    $$PWD/src/Console_core/*.cpp \
    $$PWD/src/Console_user_data_processing/*.cpp \
    $$PWD/src/Console_output_processing/Messengers/*.cpp \
    $$PWD/src/Console_output_processing/Output_configuration/*.cpp \
    $$PWD/src/Console_input_processing/*.cpp \





