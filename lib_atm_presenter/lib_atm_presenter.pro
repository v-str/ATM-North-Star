TEMPLATE = lib
TARGET = lib_atm_presenter
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang++

INCLUDEPATH += \

HEADERS += \
    $$PWD/*.h \

SOURCES += \
    $$PWD/*.cpp \

