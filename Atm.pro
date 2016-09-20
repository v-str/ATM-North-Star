TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    src \
    src/notifications_about_operations \
    src/user_identification \
    src/user_operations/credit \
    src/demo_user \
    src/user_operations/withdrawal \
    src/user_operations/statement \
    src/user_operations/refill \
    src/user \
    src/system_utility \
    src/main

DISTFILES += \
    ToDo_List

HEADERS += \
    src/user/user.h \
    src/user/user_choice.h \
    src/user/user_input.h \
    src/user/user_messenger.h \
    src/user_operations/credit/credit_messenger.h \
    src/user_operations/credit/primary_credit_operations.h \
    src/user_operations/credit/secondary_credit_operations.h \
    src/user_operations/credit/user_credit.h \
    src/user_operations/refill/refill.h \
    src/user_operations/refill/refill_messenger.h \
    src/user_operations/statement/statement.h \
    src/user_operations/statement/statement_messenger.h \
    src/user_operations/withdrawal/withdrawal.h \
    src/user_operations/withdrawal/withdrawal_messenger.h \
    src/demo_user/demo_user.h \
    src/demo_user/demo_user_messanger.h \
    src/main/initial_screen.h \
    src/notifications_about_operations/notice_about_error.h \
    src/notifications_about_operations/notice_about_successful_action.h \
    src/system_utility/system_utility.h \
    src/user_identification/cash_operator.h \
    src/user_identification/user_identifier.h

SOURCES += \
    src/user/user.cpp \
    src/user/user_choice.cpp \
    src/user/user_input.cpp \
    src/user/user_messenger.cpp \
    src/user_operations/credit/credit_messenger.cpp \
    src/user_operations/credit/primary_credit_operations.cpp \
    src/user_operations/credit/secondary_credit_operations.cpp \
    src/user_operations/credit/user_credit.cpp \
    src/user_operations/refill/refill.cpp \
    src/user_operations/refill/refill_messenger.cpp \
    src/user_operations/statement/statement.cpp \
    src/user_operations/statement/statement_messenger.cpp \
    src/user_operations/withdrawal/withdrawal.cpp \
    src/user_operations/withdrawal/withdrawal_messenger.cpp \
    src/demo_user/demo_user.cpp \
    src/demo_user/demo_user_messanger.cpp \
    src/main/initial_screen.cpp \
    src/main/main.cpp \
    src/notifications_about_operations/notice_about_error.cpp \
    src/notifications_about_operations/notice_about_successful_action.cpp \
    src/system_utility/system_utility.cpp \
    src/user_identification/cash_operator.cpp \
    src/user_identification/user_identifier.cpp

