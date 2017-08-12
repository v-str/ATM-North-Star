TEMPLATE = lib
TARGET = lib_atm_model
CONFIG = staticlib

QMAKE_CXX = ccache clang++

INCLUDEPATH += \
    $$PWD/console_version/transaction_menu \
#    $$PWD/atm_operations/credit_operations \ #deprecated code, should be removed
    $$PWD/console_version/authentication \
    $$PWD/console_version/initial_menu \
    $$PWD/application_launch \
    $$PWD/graphical_version \
#    $$PWD/atm_operations \ #deprecated code, should be removed
#    $$PWD/user_data \ #deprecated code, should be removed

HEADERS += \
    $$PWD/console_version/transaction_menu/*.h \
#    $$PWD/atm_operations/credit_operations/*.h \
    $$PWD/console_version/authentication/*.h \
    $$PWD/console_version/initial_menu/*.h \
    $$PWD/application_launch/*.h \
    $$PWD/graphical_version/*.h \
    $$PWD/atm_operations/*.h \
    $$PWD/user_data/*.h \

SOURCES += \
#    $$PWD/atm_operations/credit_operations/*.cpp \
    $$PWD/console_version/transaction_menu/*.cpp \
    $$PWD/console_version/authentication/*.cpp \
    $$PWD/console_version/initial_menu/*.cpp \
    $$PWD/application_launch/*.cpp \
    $$PWD/graphical_version/*.cpp \
    $$PWD/atm_operations/*.cpp \
    $$PWD/user_data/*.cpp \
