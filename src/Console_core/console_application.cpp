#include "console_application.h"
#include "output_setup.h"

void ConsoleApplication::RunProgram() {
  OutputSetup::SetupTwoStreamsForOutput();

  int user_choice = GetProgramMode();

  if (user_choice == kDemoMode) {
    demo_mode_.ShowDemoMode();
    if (demo_mode_.UserWantToRegistrate()) {
      RegisterUser();
    }
  } else if (user_choice == kRegistration) {
    RegisterUser();
  } else {
    user_messenger_.ShowIncorrectRegisterData();
  }

  if (registrator_.IsCorrectRegistration()) {
    DisplayMenu();
  }
  user_messenger_.WishAGoodDay();
}

int ConsoleApplication::GetProgramMode() {
  init_screen_.DisplayInitialScreen();
  return user_input_.GetValueFromUser();
}

void ConsoleApplication::RegisterUser() {
  registrator_.RegisterUser(cash_operator_, user_identifier_);
}

void ConsoleApplication::DisplayMenu() {
  do {
    StartMainMenu();
  } while (!is_user_want_to_exit_);
}

void ConsoleApplication::StartMainMenu() {
  user_messenger_.ShowMainMenu();
  DoProgramSection(user_input_.GetValueFromUser());
}

void ConsoleApplication::DoProgramSection(int choice) {
  if (choice == kAccountSection) {
    ShowAccountInfo();
  } else if (choice == kRefillSection) {
    RefillOperation();
  } else if (choice == kCreditSection) {
    CreditApplication();
  } else if (choice == kWidthdrawalSection) {
    WithdrawCash();
  } else if (choice == kStatementSection) {
    Statement();
  } else if (choice == kExitSection) {
    user_messenger_.SuggestUserToExit();
    is_user_want_to_exit_ = user_input_.SuggestUserToExitWithConfirmationMenu();
  } else {
    is_user_want_to_exit_ = user_input_.ShowIncorrectMessage();
  }
}

void ConsoleApplication::ShowAccountInfo() {
  account_informator_.DisplayAccountInformation(user_identifier_,
                                                cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void ConsoleApplication::RefillOperation() {
  refill_.StartRefillOperation(cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void ConsoleApplication::CreditApplication() {
  user_credit_.StartCreditOperation(user_identifier_, cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void ConsoleApplication::WithdrawCash() {
  withdrawal_.WithdrawCashFromUser(cash_operator_, user_identifier_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void ConsoleApplication::Statement() {
  statement_.ShowStatement(cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}
