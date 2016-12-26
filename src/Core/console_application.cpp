#include "console_application.h"
#include "output_setup.h"

void ConsoleApplication::RunProgram() {
  OutputSetup::SetupTwoStreamsForOutput();

  int user_choice = GetProgramMode();

  RunProgramModeBasedOnUserChoice(user_choice);
}

int ConsoleApplication::GetProgramMode() {
  init_screen_.DisplayInitialScreen();
  return user_input_.GetValueFromUser();
}

void ConsoleApplication::RunProgramModeBasedOnUserChoice(int user_choice) {
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
    DisplayMainMenu();
  }
  user_messenger_.WishAGoodDay();
}

void ConsoleApplication::RegisterUser() {
  registrator_.RegisterUser(atm_user_);
}

void ConsoleApplication::DisplayMainMenu() {
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
  account_informator_.DisplayAccountInformation(&atm_user_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void ConsoleApplication::RefillOperation() {
  refill_.StartRefillOperation(&atm_user_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void ConsoleApplication::CreditApplication() {
  user_credit_.StartCreditOperation(atm_user_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void ConsoleApplication::WithdrawCash() {
  withdrawal_.WithdrawCashFromUser(&atm_user_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void ConsoleApplication::Statement() {
  statement_.ShowStatement(atm_user_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}
