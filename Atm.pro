TEMPLATE = app
CONFIG += console c++11
QMAKE_CXXFLAGS += -std=c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    src \
    src/notifications_about_operations \
    src/user_identification \
    src/atm_operations/credit \
    src/atm_operations/withdrawal \
    src/atm_operations/statement \
    src/atm_operations/refill \
    src/demo_mode \
    src/user \
    src/system_utility \
    src/start_program

DISTFILES += \
    ToDo_List

HEADERS += \
    src/user/user_choice.h \
    src/user/user_input.h \
    src/user/user_messenger.h \
    src/atm_operations/credit/credit_messenger.h \
    src/atm_operations/credit/secondary_credit_operations.h \
    src/atm_operations/credit/user_credit.h \
    src/atm_operations/refill/refill.h \
    src/atm_operations/refill/refill_messenger.h \
    src/atm_operations/statement/statement.h \
    src/atm_operations/statement/statement_messenger.h \
    src/atm_operations/withdrawal/withdrawal.h \
    src/atm_operations/withdrawal/withdrawal_messenger.h \
    src/demo_mode/demo_user.h \
    src/demo_mode/demo_user_messanger.h \
    src/start_program/initial_screen.h \
    src/notifications_about_operations/notice_about_error.h \
    src/notifications_about_operations/notice_about_successful_action.h \
    src/system_utility/system_utility.h \
    src/user_identification/cash_operator.h \
    src/user/application.h \
    src/notifications_about_operations/notice_messenger.h \
    src/atm_operations/credit/credit_offer.h \
    src/atm_operations/credit/credit_page.h \
    src/atm_operations/credit/credit.h \
    src/user_identification/user_identifier.h \
    src/user/user_registrator.h \
    src/user/registration_messenger.h

SOURCES += \
    src/user/user_choice.cpp \
    src/user/user_input.cpp \
    src/user/user_messenger.cpp \
    src/atm_operations/credit/credit_messenger.cpp \
    src/atm_operations/credit/secondary_credit_operations.cpp \
    src/atm_operations/credit/user_credit.cpp \
    src/atm_operations/refill/refill.cpp \
    src/atm_operations/refill/refill_messenger.cpp \
    src/atm_operations/statement/statement.cpp \
    src/atm_operations/statement/statement_messenger.cpp \
    src/atm_operations/withdrawal/withdrawal.cpp \
    src/atm_operations/withdrawal/withdrawal_messenger.cpp \
    src/demo_mode/demo_user.cpp \
    src/demo_mode/demo_user_messanger.cpp \
    src/start_program/initial_screen.cpp \
    src/start_program/main.cpp \
    src/notifications_about_operations/notice_about_error.cpp \
    src/notifications_about_operations/notice_about_successful_action.cpp \
    src/system_utility/system_utility.cpp \
    src/user_identification/cash_operator.cpp \
    src/user/application.cpp \
    src/notifications_about_operations/notice_messenger.cpp \
    src/atm_operations/credit/credit_offer.cpp \
    src/atm_operations/credit/credit_page.cpp \
    src/atm_operations/credit/credit.cpp \
    src/user_identification/user_identifier.cpp \
    src/user/user_registrator.cpp \
    src/user/registration_messenger.cpp

