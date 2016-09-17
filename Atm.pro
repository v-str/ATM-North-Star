TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    src \
    src/notifications \
    src/user_identification \
    src/credit/user_credit \
    src/credit/credit_operations \
    src/credit/credit_messenger \
    src/demo_user
    src/withdrawal

SOURCES += \
    src/main.cpp \
    src/user.cpp \
    src/system_utility.cpp \
    src/user_input.cpp \
    src/initial_screen.cpp \
    src/notifications/notice_about_error.cpp \
    src/user_choice.cpp \
    src/user_messenger.cpp \
    src/credit/user_credit/user_credit.cpp \
    src/credit/credit_messenger/credit_messenger.cpp \
    src/demo_user/demo_user.cpp \
    src/demo_user/demo_user_messanger.cpp \
    src/user_identification/user_identifier.cpp \
    src/credit/credit_operations/primary_credit_operations.cpp \
    src/credit/credit_operations/secondary_credit_operations.cpp \
    src/notifications/notice_about_successful_action.cpp \
    src/user_identification/cash_operator.cpp \
    src/withdrawal/withdrawal.cpp \
    src/withdrawal/withdrawal_messenger.cpp

HEADERS += \
    src/user.h \
    src/system_utility.h \
    src/user_input.h \
    src/initial_screen.h \
    src/notifications/notice_about_error.h \
    src/user_choice.h \
    src/user_messenger.h \
    src/credit/user_credit/user_credit.h \
    src/credit/credit_messenger/credit_messenger.h \
    src/demo_user/demo_user.h \
    src/demo_user/demo_user_messanger.h \
    src/user_identification/user_identifier.h \
    src/credit/credit_operations/primary_credit_operations.h \
    src/credit/credit_operations/secondary_credit_operations.h \
    src/notifications/notice_about_successful_action.h \
    src/user_identification/cash_operator.h \
    src/withdrawal/withdrawal.h \
    src/withdrawal/withdrawal_messenger.h
