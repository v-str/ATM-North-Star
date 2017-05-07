TEMPLATE = lib
TARGET = atm_core
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache g++

INCLUDEPATH += \
    $$PWD/atm_machine \
    $$PWD/atm_operations \
    $$PWD/credit_department \
    $$PWD/user_data \
    $$PWD/data_validation \

HEADERS += \
    $$PWD/atm_machine/*.h \
    $$PWD/atm_operations/*.h \
    $$PWD/credit_department/*.h \
    $$PWD/user_data/*.h / \
    $$PWD/data_validation/*.h \
    atm_operations/refill.h

SOURCES += \
    $$PWD/atm_machine/*.cpp \
    $$PWD/atm_operations/*.cpp \
    $$PWD/credit_department/*.cpp \
    $$PWD/user_data/*.cpp \
    $$PWD/data_validation/*.cpp \
    atm_operations/refill.cpp
