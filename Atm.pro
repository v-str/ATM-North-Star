TEMPLATE = app
CONFIG += console c++11
QMAKE_CXXFLAGS += -std=c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    src \
    src/notifications_about_operations \
    src/user_identification \
    src/atm_operations/credit \
    src/atm_operations/withdrawal \
    src/atm_operations/statement \
    src/atm_operations/refill \
    src/atm_operations/account_info \
    src/help_mode \
    src/user \
    src/system_utility \
    src/atm_application \
    src/input_processing \
    src/initial_menu

DISTFILES += \
    ToDo_List

HEADERS += \
    $$PWD/src/user/*.h \
    $$PWD/src/notifications_about_operations/*.h \
    $$PWD/src/atm_operations/credit/*.h \
    $$PWD/src/atm_operations/refill/*.h \
    $$PWD/src/atm_operations/statement/*.h \
    $$PWD/src/atm_operations/withdrawal/*.h \
    $$PWD/src/atm_operations/account_info/*.h \
    $$PWD/src/help_mode/*.h \
    $$PWD/src/system_utility/*.h \
    $$PWD/src/user_identification/*.h \
    $$PWD/src/initial_menu/*.h \
    $$PWD/src/input_processing/*.h \
    $$PWD/src/registration/*.h \
    $$PWD/src/atm_application/*.h

SOURCES += \
    $$PWD/src/user/*.cpp \
    $$PWD/src/notifications_about_operations/*.cpp \
    $$PWD/src/atm_operations/credit/*.cpp \
    $$PWD/src/atm_operations/refill/*.cpp \
    $$PWD/src/atm_operations/statement/*.cpp \
    $$PWD/src/atm_operations/withdrawal/*.cpp \
    $$PWD/src/atm_operations/account_info/*.cpp \
    $$PWD/src/help_mode/*.cpp \
    $$PWD/src/system_utility/*.cpp \
    $$PWD/src/user_identification/*.cpp \
    $$PWD/src/initial_menu/*.cpp \
    $$PWD/src/input_processing/*.cpp \
    $$PWD/src/registration/*.cpp \
    $$PWD/src/atm_application/*.cpp

