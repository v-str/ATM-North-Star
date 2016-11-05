TEMPLATE = app
CONFIG += console c++11
QMAKE_CXXFLAGS += -std=c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    src \
    src/Application \
    src/Atm_operations \
    src/Support \
    src/Messengers \
    src/Input_processing

DISTFILES += \
    ToDo_List

HEADERS += \
    $$PWD/src/Application/*.h \
    $$PWD/src/Atm_operations/*.h \
    $$PWD/src/Support/*.h \
    $$PWD/src/Messengers/*.h \
    $$PWD/src/Input_processing/*.h



SOURCES += \
    $$PWD/src/Application/*.cpp \
    $$PWD/src/Atm_operations/*.cpp \
    $$PWD/src/Support/*.cpp \
    $$PWD/src/Messengers/*.cpp \
    $$PWD/src/Input_processing/*.cpp



