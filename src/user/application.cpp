#include "application.h"

static const int kDemoMode = 1;
static const int kRegistration = 2;

void Application::XxX() {
  initial_screen_.Logotype();
  initial_screen_.InitialMenu();
  int choice = user_input_.GetChoiceFromUser();

  if (choice == kDemoMode) {
    demo_mode_.ShowDemoMode();
    if (demo_mode_.UserWantToRegistrate()) {
      RunProgram();
    }
  } else if (choice == kRegistration) {
    RunProgram();

  } else {
    initial_screen_.Error();
  }
  user_messenger_.WishAGoodDay();
}

void Application::RunProgram() {
  registrator_.Register(cash_operator_, user_identifier_);
  utility_.ClearScreen();

  do {
    DisplayProgramMenu();
  } while (!is_user_dont_want_to_exit_);
}

void Application::DisplayProgramMenu() {
  user_messenger_.ShowTransactionMenu();
  DoProgramSection(user_input_.GetChoiceFromUser());
}

void Application::DoProgramSection(int choice) {
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
    is_user_dont_want_to_exit_ =
        user_input_.SuggestUserToExitWithConfirmationMenu();
  } else {
    user_input_.ShowIncorrectMessage();
  }
}

void Application::ShowAccountInfo() {
  user_messenger_.ShowAccountInformation(user_identifier_, cash_operator_);
  is_user_dont_want_to_exit_ = user_input_.SuggestUserToExit();
}

void Application::RefillOperation() {
  refill_.StartRefillOperation(cash_operator_);
  is_user_dont_want_to_exit_ = user_input_.SuggestUserToExit();
}

void Application::CreditApplication() {
  user_credit_.StartCreditOperation(user_identifier_, cash_operator_);
  is_user_dont_want_to_exit_ = user_input_.SuggestUserToExit();
}

void Application::WithdrawCash() {
  withdrawal_.WithdrawCashFromUser(cash_operator_, user_identifier_);
  is_user_dont_want_to_exit_ = user_input_.SuggestUserToExit();
}

void Application::Statement() {
  statement_.ShowStatement(cash_operator_);
  is_user_dont_want_to_exit_ = user_input_.SuggestUserToExit();
}
