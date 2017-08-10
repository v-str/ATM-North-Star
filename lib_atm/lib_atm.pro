TEMPLATE = lib
TARGET = lib_atm
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang++

INCLUDEPATH += \
    $$PWD/incoming_data_processing \
    $$PWD/credit_department \
    $$PWD/atm_operations \
    $$PWD/atm_machine \
    $$PWD/user_data \

HEADERS += \
    $$PWD/incoming_data_processing/*.h \
    $$PWD/credit_department/*.h \
    $$PWD/atm_operations/*.h \
    $$PWD/atm_machine/*.h \
    $$PWD/user_data/*.h / \

SOURCES += \
    $$PWD/incoming_data_processing/*.cpp \
    $$PWD/credit_department/*.cpp \
    $$PWD/atm_operations/*.cpp \
    $$PWD/atm_machine/*.cpp \
    $$PWD/user_data/*.cpp \
