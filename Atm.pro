TEMPLATE = subdirs

SUBDIRS += \
    src \
    lib_console_output \

src.depends = lib_console_output

DISTFILES += \
    ToDo_List






