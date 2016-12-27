TEMPLATE = app
CONFIG += console c++11
CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11

CONFIG -= app_bundle \
    qt

HEADERS += \
    $$PWD/application/*.h \
    $$PWD/core/*.h \
    $$PWD/user_data/*.h \
    $$PWD/input/*.h \


SOURCES += \
    $$PWD/application/*.cpp \
    $$PWD/core/*.cpp \
    $$PWD/user_data/*.cpp \
    $$PWD/input/*.cpp \

INCLUDEPATH += ../console_output

LIBS += -L../console_output -lconsole_output


