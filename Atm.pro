TEMPLATE = subdirs

SUBDIRS += \
    src \
    lib_console_output \
    lib_gui \

src.depends = lib_console_output
src.depends = lib_gui

DISTFILES += \
    ToDo_List






