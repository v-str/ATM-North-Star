TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp \
    src/user.cpp \
    src/system_utility.cpp \
    src/demo_user.cpp \
    src/user_input.cpp \
    src/demo_user_messanger.cpp \
    src/initial_screen.cpp \
    src/user_messanger.cpp \
    src/user_credit.cpp \
    src/identification_of_user.cpp \
    src/notice_about_error.cpp \
    src/user_choice.cpp \
    src/credit_messanger.cpp

HEADERS += \
    src/user.h \
    src/system_utility.h \
    src/demo_user.h \
    src/user_input.h \
    src/demo_user_messanger.h \
    src/initial_screen.h \
    src/user_messanger.h \
    src/user_credit.h \
    src/account_info.h \
    src/identification_of_user.h \
    src/notice_about_error.h \
    src/user_choice.h \
    src/credit_messanger.h
