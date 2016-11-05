TEMPLATE = app
CONFIG += console c++11
QMAKE_CXXFLAGS += -std=c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    src \
    src/Application \
    src/Atm_operations \
    src/Atm_operations/account_info \
    src/Atm_operations/credit \
    src/Atm_operations/refill \
    src/Atm_operations/statement \
    src/Atm_operations/withdrawal \
    src/Maintenance

DISTFILES += \
    ToDo_List

HEADERS += \
    $$PWD/src/Application/*.h \
    $$PWD/src/Atm_operations/account_info/*.h \
    $$PWD/src/Atm_operations/credit/*.h \
    $$PWD/src/Atm_operations/refill/*.h \
    $$PWD/src/Atm_operations/statement/*.h \
    $$PWD/src/Atm_operations/withdrawal/*.h \
    $$PWD/src/Maintenance/*.h \


SOURCES += \
    $$PWD/src/Application/*.cpp \
    $$PWD/src/Atm_operations/account_info/*.cpp \
    $$PWD/src/Atm_operations/credit/*.cpp \
    $$PWD/src/Atm_operations/refill/*.cpp \
    $$PWD/src/Atm_operations/statement/*.cpp \
    $$PWD/src/Atm_operations/withdrawal/*.cpp \
    $$PWD/src/Maintenance/*.cpp \


