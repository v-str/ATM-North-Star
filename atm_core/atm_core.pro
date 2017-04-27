TEMPLATE = lib
TARGET = atm_core
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache g++

INCLUDEPATH += \
    $$PWD/credit_department \

HEADERS += \
    $$PWD/credit_department/*.h \

SOURCES += \
    $$PWD/credit_department/*.cpp \
