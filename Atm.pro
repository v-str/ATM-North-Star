TARGET = Atm

TEMPLATE = app

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11

CONFIG -= app_bundle \
    qt

INCLUDEPATH += \
    src \
    src/Application \
    src/Core \
    src/User_data \
    src/Console_output/Messengers \
    src/Console_output/Output_configuration \
    src/Input

DISTFILES += \
    ToDo_List

HEADERS += \
    $$PWD/src/Application/*.h \
    $$PWD/src/Core/*.h \
    $$PWD/src/User_data/*.h \
    $$PWD/src/Console_output/Messengers/*.h \
    $$PWD/src/Console_output/Output_configuration/*.h \
    $$PWD/src/Input/*.h \


SOURCES += \
    $$PWD/src/Application/*.cpp \
    $$PWD/src/Core/*.cpp \
    $$PWD/src/User_data/*.cpp \
    $$PWD/src/Console_output/Messengers/*.cpp \
    $$PWD/src/Console_output/Output_configuration/*.cpp \
    $$PWD/src/Input/*.cpp \





