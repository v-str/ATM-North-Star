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
    src/atm_operations/account_info \
    src/demo_mode \
    src/user \
    src/system_utility \
    src/atm_application

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
    src/atm_operations/statement/statement_messenger.h \
    src/atm_operations/withdrawal/withdrawal.h \
    src/atm_operations/withdrawal/withdrawal_messenger.h \
    src/demo_mode/demo_user.h \
    src/demo_mode/demo_user_messanger.h \
    src/atm_application/application.h \
    src/system_utility/system_utility.h \
    src/user_identification/cash_operator.h \
    src/notifications_about_operations/notice_messenger.h \
    src/atm_operations/credit/credit_offer.h \
    src/atm_operations/credit/credit_page.h \
    src/atm_operations/credit/credit.h \
    src/user_identification/user_identifier.h \
    src/user/user_registrator.h \
    src/user/registration_messenger.h \
    src/notifications_about_operations/notifier.h \
    src/user_identification/user_identification_data_provider.h \
    src/atm_operations/account_info/account_informator.h \
    src/atm_operations/account_info/account_messenger.h \
    src/atm_operations/account_info/information_screen.h \
    src/user_identification/identification_messenger.h \
    src/atm_operations/statement/user_statement.h \
    src/notifications_about_operations/notice_about_successful_action.h \
    src/initial_menu/initial_menu.h \
    src/initial_menu/initial_screen.h

SOURCES += \
    src/user/user_choice.cpp \
    src/user/user_input.cpp \
    src/user/user_messenger.cpp \
    src/atm_operations/credit/credit_messenger.cpp \
    src/atm_operations/credit/secondary_credit_operations.cpp \
    src/atm_operations/credit/user_credit.cpp \
    src/atm_operations/refill/refill.cpp \
    src/atm_operations/refill/refill_messenger.cpp \
    src/atm_operations/statement/statement_messenger.cpp \
    src/atm_operations/withdrawal/withdrawal.cpp \
    src/atm_operations/withdrawal/withdrawal_messenger.cpp \
    src/demo_mode/demo_user.cpp \
    src/demo_mode/demo_user_messanger.cpp \
    src/atm_application/main.cpp \
    src/atm_application/application.cpp \
    src/notifications_about_operations/notice_about_successful_action.cpp \
    src/system_utility/system_utility.cpp \
    src/user_identification/cash_operator.cpp \
    src/notifications_about_operations/notice_messenger.cpp \
    src/atm_operations/credit/credit_offer.cpp \
    src/atm_operations/credit/credit_page.cpp \
    src/atm_operations/credit/credit.cpp \
    src/user_identification/user_identifier.cpp \
    src/user/user_registrator.cpp \
    src/user/registration_messenger.cpp \
    src/notifications_about_operations/notifier.cpp \
    src/user_identification/user_identification_data_provider.cpp \
    src/atm_operations/account_info/account_informator.cpp \
    src/atm_operations/account_info/account_messenger.cpp \
    src/atm_operations/account_info/information_screen.cpp \
    src/user_identification/identification_messenger.cpp \
    src/atm_operations/statement/user_statement.cpp \
    src/initial_menu/initial_menu.cpp \
    src/initial_menu/initial_screen.cpp

