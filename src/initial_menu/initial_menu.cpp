#include "initial_menu.h"

void InitialMenu::RunProgram() {
  int user_choice = user_input_.GetChoiceFromUser();

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

void InitialMenu::RegisterUser() {
  registrator_.RegisterUser(cash_operator_, user_identifier_);
}

void InitialMenu::DisplayMenu() {
  do {
    StartMainMenu();
  } while (!is_user_want_to_exit_);
}

void InitialMenu::StartMainMenu() {
  utility_.ClearScreen();
  user_messenger_.ShowMainMenu();
  DoProgramSection(user_input_.GetChoiceFromUser());
}

void InitialMenu::DoProgramSection(int choice) {
  utility_.ClearScreen();

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

void InitialMenu::ShowAccountInfo() {
  account_informator_.DisplayAccountInformation(user_identifier_,
                                                cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void InitialMenu::RefillOperation() {
  refill_.StartRefillOperation(cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void InitialMenu::CreditApplication() {
  user_credit_.StartCreditOperation(user_identifier_, cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void InitialMenu::WithdrawCash() {
  withdrawal_.WithdrawCashFromUser(cash_operator_, user_identifier_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void InitialMenu::Statement() {
  statement_.ShowStatement(cash_operator_);
  is_user_want_to_exit_ = user_input_.SuggestUserToExit();
}
