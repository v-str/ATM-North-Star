TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp \
    src/screen.cpp \
    src/user.cpp \
    src/system_utility.cpp \
    src/demo_user.cpp

HEADERS += \
    src/screen.h \
    src/user.h \
    src/system_utility.h \
    src/demo_user.h
