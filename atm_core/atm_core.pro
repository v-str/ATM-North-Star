TEMPLATE = lib
TARGET = atm_core
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache g++

INCLUDEPATH += \
    $$PWD/credit_department \
    $$PWD/user_data \

HEADERS += \
    $$PWD/credit_department/*.h \
    $$PWD/user_data/*.h / \

SOURCES += \
    $$PWD/credit_department/*.cpp \
    $$PWD/user_data/*.cpp \

