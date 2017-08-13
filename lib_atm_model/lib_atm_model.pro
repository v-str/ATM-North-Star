TEMPLATE = lib
TARGET = lib_atm_model
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache clang++

INCLUDEPATH += \
    $$PWD/incoming_data_handling \
    $$PWD/interface_presenter \
    $$PWD/credit_department \
    $$PWD/atm_operations \
    $$PWD/interaction \
    $$PWD/user_data \

HEADERS += \
    $$PWD/incoming_data_handling/*.h \
    $$PWD/interface_presenter/*.h \
    $$PWD/credit_department/*.h \
    $$PWD/atm_operations/*.h \
    $$PWD/interaction/*.h \
    $$PWD/user_data/*.h / \

SOURCES += \
    $$PWD/incoming_data_handling/*.cpp \
    $$PWD/interface_presenter/*.cpp \
    $$PWD/credit_department/*.cpp \
    $$PWD/atm_operations/*.cpp \
    $$PWD/interaction/*.cpp \
    $$PWD/user_data/*.cpp \
