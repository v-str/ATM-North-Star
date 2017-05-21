TEMPLATE = lib
TARGET = atm
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang++

INCLUDEPATH += \
    $$PWD/atm_machine \
    $$PWD/atm_operations \
    $$PWD/credit_department \
    $$PWD/user_data \
    $$PWD/incoming_data_processing \

HEADERS += \
    $$PWD/atm_machine/*.h \
    $$PWD/atm_operations/*.h \
    $$PWD/credit_department/*.h \
    $$PWD/user_data/*.h / \
    $$PWD/incoming_data_processing/*.h \

SOURCES += \
    $$PWD/atm_machine/*.cpp \
    $$PWD/atm_operations/*.cpp \
    $$PWD/credit_department/*.cpp \
    $$PWD/user_data/*.cpp \
    $$PWD/incoming_data_processing/*.cpp \
