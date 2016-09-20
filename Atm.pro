TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    src \
    src/notifications_about_operations \
    src/user_identification \
    src/credit/user_credit \
    src/credit/credit_operations \
    src/credit/credit_messenger \
    src/demo_user \
    src/withdrawal \
    src/statement \
    src/refill \
    src/user_operations \
    src/user_operations/user \
    src/user_operations/user_messenger \
    src/user_operations/user_choice_and_input \
    src/system_utility \
    src/main

SOURCES += \
    src/main/main.cpp \
    src/user_operations/user/user.cpp \
    src/user_operations/user_messenger/user_messenger.cpp \
    src/user_operations/user_choice_and_input/user_input.cpp \
    src/user_operations/user_choice_and_input/user_choice.cpp \
    src/system_utility/system_utility.cpp \
    src/main/initial_screen.cpp \
    src/notifications_about_operations/notice_about_error.cpp \
    src/credit/user_credit/user_credit.cpp \
    src/credit/credit_messenger/credit_messenger.cpp \
    src/demo_user/demo_user.cpp \
    src/demo_user/demo_user_messanger.cpp \
    src/user_identification/user_identifier.cpp \
    src/credit/credit_operations/primary_credit_operations.cpp \
    src/credit/credit_operations/secondary_credit_operations.cpp \
    src/notifications_about_operations/notice_about_successful_action.cpp \
    src/user_identification/cash_operator.cpp \
    src/withdrawal/withdrawal.cpp \
    src/withdrawal/withdrawal_messenger.cpp \
    src/statement/statement.cpp \
    src/statement/statement_messenger.cpp \
    src/refill/refill.cpp \
    src/refill/refill_messenger.cpp


HEADERS += \
    src/user_operations/user/user.h \
    src/user_operations/user_messenger/user_messenger.h \
    src/user_operations/user_choice_and_input/user_input.h \
    src/user_operations/user_choice_and_input/user_choice.h \
    src/system_utility/system_utility.h \
    src/main/initial_screen.h \
    src/notifications_about_operations/notice_about_error.h \
    src/credit/user_credit/user_credit.h \
    src/credit/credit_messenger/credit_messenger.h \
    src/demo_user/demo_user.h \
    src/demo_user/demo_user_messanger.h \
    src/user_identification/user_identifier.h \
    src/credit/credit_operations/primary_credit_operations.h \
    src/credit/credit_operations/secondary_credit_operations.h \
    src/notifications_about_operations/notice_about_successful_action.h \
    src/user_identification/cash_operator.h \
    src/withdrawal/withdrawal.h \
    src/withdrawal/withdrawal_messenger.h \
    src/statement/statement.h \
    src/statement/statement_messenger.h \
    src/refill/refill.h \
    src/refill/refill_messenger.h
