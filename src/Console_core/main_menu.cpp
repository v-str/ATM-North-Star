#include "main_menu.h"
#include "output_setup.h"

void MainMenu::RunMainMenu() {
  OutputSetup::SetupTwoStreamsForOutput();

  init_screen_.DisplayInitialScreen();

  int user_choice = user_input_.GetValueFromUser();

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

void MainMenu::RegisterUser() {
  registrator_.RegisterUser(cash_operator_, user_identifier_);
}

void MainMenu::DisplayMenu() {
  do {
    StartMainMenu();
  } while (!is_user_want_to_exit_);
}

void MainMenu::StartMainMenu() {
  user_messenger_.ShowMainMenu();
  DoProgramSection(user_input_.GetValueFromUser());
}

void MainMenu::DoProgramSection(int choice) {
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

void MainMenu::ShowAccountInfo() {
  account_informator_.DisplayAccountInformation(user_identifier_,
                                                cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void MainMenu::RefillOperation() {
  refill_.StartRefillOperation(cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void MainMenu::CreditApplication() {
  user_credit_.StartCreditOperation(user_identifier_, cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void MainMenu::WithdrawCash() {
  withdrawal_.WithdrawCashFromUser(cash_operator_, user_identifier_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void MainMenu::Statement() {
  statement_.ShowStatement(cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}
