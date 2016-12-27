TEMPLATE = lib
CONFIG = staticlib

INCLUDEPATH += \
    ../console_output/messengers \
    ../console_output/output_configuration \

HEADERS += \
    $$PWD/messengers/*.h \
    $$PWD/output_configuration/*.h \

SOURCES += \
    $$PWD/messengers/*.cpp \
    $$PWD/output_configuration/*.cpp \


