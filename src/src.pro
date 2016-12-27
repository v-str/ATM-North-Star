TEMPLATE = app
CONFIG += console c++11
CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11

CONFIG -= app_bundle \
    qt

INCLUDEPATH += \
    ../console_output/messengers \
    ../console_output/output_configuration \
    ../src/application \
    ../src/core \
    ../src/user_data \
    ../src/input \

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


LIBS += -L../console_output -lconsole_output


