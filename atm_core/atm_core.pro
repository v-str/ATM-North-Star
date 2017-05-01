TEMPLATE = lib
TARGET = atm_core
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache g++

INCLUDEPATH += \
    $$PWD/atm_operations \
    $$PWD/credit_department \
    $$PWD/user_data \

HEADERS += \
    $$PWD/atm_operations/*.h \
    $$PWD/credit_department/*.h \
    $$PWD/user_data/*.h / \

SOURCES += \
    $$PWD/atm_operations/*.cpp \
    $$PWD/credit_department/*.cpp \
    $$PWD/user_data/*.cpp \

