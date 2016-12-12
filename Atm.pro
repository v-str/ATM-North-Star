TARGET = Atm

TEMPLATE = app

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11

CONFIG -= app_bundle \
    qt

INCLUDEPATH += \
    src \
    src/Application \
    src/Atm_operations \
    src/Support \
    src/Console_output_processing/Messengers \
    src/Console_output_processing/Output_configuration \
    src/Input_processing

DISTFILES += \
    ToDo_List

HEADERS += \
    $$PWD/src/Application/*.h \
    $$PWD/src/Atm_operations/*.h \
    $$PWD/src/Support/*.h \
    $$PWD/src/Console_output_processing/Messengers/*.h \
    $$PWD/src/Console_output_processing/Output_configuration/*.h \
    $$PWD/src/Input_processing/*.h \

SOURCES += \
    $$PWD/src/Application/*.cpp \
    $$PWD/src/Atm_operations/*.cpp \
    $$PWD/src/Support/*.cpp \
    $$PWD/src/Console_output_processing/Messengers/*.cpp \
    $$PWD/src/Console_output_processing/Output_configuration/*.cpp \
    $$PWD/src/Input_processing/*.cpp \




