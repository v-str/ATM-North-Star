#include "application.h"
#include "output_setup.h"

void Application::RunProgram() {
  OutputSetup::SetupTwoStreamsForOutput();

  int user_choice = GetProgramMode();

  RunProgramModeBasedOnUserChoice(user_choice);
}

int Application::GetProgramMode() {
  init_screen_.DisplayInitialScreen();
  return user_input_.GetValueFromUser();
}

void Application::RunProgramModeBasedOnUserChoice(int user_choice) {
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

void Application::RegisterUser() {
  registrator_.RegisterUser(atm_user_);
}

void Application::DisplayMainMenu() {
  do {
    StartMainMenu();
  } while (!is_user_want_to_exit_);
}

void Application::StartMainMenu() {
  user_messenger_.ShowMainMenu();
  DoProgramSection(user_input_.GetValueFromUser());
}

void Application::DoProgramSection(int choice) {
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

void Application::ShowAccountInfo() {
  account_informator_.DisplayAccountInformation(&atm_user_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void Application::RefillOperation() {
  refill_.StartRefillOperation(&atm_user_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void Application::CreditApplication() {
  user_credit_.StartCreditOperation(&atm_user_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void Application::WithdrawCash() {
  withdrawal_.WithdrawCashFromUser(&atm_user_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void Application::Statement() {
  statement_.ShowStatement(&atm_user_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}
