TEMPLATE = subdirs

SUBDIRS += \
    src \
    console_output \

src.depends = console_output

DISTFILES += \
    ToDo_List






