TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    src/credit \
    src/demo_user \
    src

SOURCES += \
    src/main.cpp \
    src/user.cpp \
    src/system_utility.cpp \
    src/user_input.cpp \
    src/initial_screen.cpp \
    src/notice_about_error.cpp \
    src/user_choice.cpp \
    src/user_messenger.cpp \
    src/user_identificator.cpp \
    src/credit/user_credit.cpp \
    src/credit/credit_messenger.cpp \
    src/demo_user/demo_user.cpp \
    src/demo_user/demo_user_messanger.cpp

HEADERS += \
    src/user.h \
    src/system_utility.h \
    src/user_input.h \
    src/initial_screen.h \
    src/account_info.h \
    src/notice_about_error.h \
    src/user_choice.h \
    src/user_messenger.h \
    src/user_identificator.h \
    src/credit/user_credit.h \
    src/credit/credit_messenger.h \
    src/demo_user/demo_user.h \
    src/demo_user/demo_user_messanger.h
