TEMPLATE = lib
CONFIG = staticlib

INCLUDEPATH += \
    $$PWD/messengers \
    $$PWD/output_configuration \

HEADERS += \
    $$PWD/messengers/*.h \
    $$PWD/output_configuration/*.h \

SOURCES += \
    $$PWD/messengers/*.cpp \
    $$PWD/output_configuration/*.cpp \


