#include "application.h"
#include "output_setup.h"

void Application::RunProgram(std::size_t mode) {
  if (mode == kConsoleMode) {
    OutputSetup::SetupTwoStreamsForOutput();
  }
  int user_choice = GetProgramSection();

  RunSectionBasedOnChoice(user_choice);
}

int Application::GetProgramSection() {
  init_screen_.DisplayInitialScreen();
  return user_input_.GetValueFromUser();
}

void Application::RunSectionBasedOnChoice(int user_choice) {
  if (user_choice == kDemonstration) {
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

void Application::RegisterUser() { registrator_.RegisterUser(atm_user_); }

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
    is_user_want_to_exit_ = user_input_.SuggestUserToExit();
  } else {
    is_user_want_to_exit_ = user_input_.ShowIncorrectMessage();
  }
}

void Application::ShowAccountInfo() {
  account_informator_.DisplayAccountInformation(&atm_user_);
  GetExitResult();
}

void Application::RefillOperation() {
  refill_.StartRefillOperation(&atm_user_);
  GetExitResult();
}

void Application::CreditApplication() {
  user_credit_.StartCreditOperation(&atm_user_);
  GetExitResult();
}

void Application::WithdrawCash() {
  withdrawal_.WithdrawCashFromUser(&atm_user_);
  GetExitResult();
}

void Application::Statement() {
  statement_.ShowStatement(&atm_user_);
  GetExitResult();
}

void Application::GetExitResult() {
  user_messenger_.SuggestExit();
  int result_of_exit = 0;
  for (;;) {
    result_of_exit = user_input_.GetValueFromUser();

    if (result_of_exit == kMainMenu) {
      is_user_want_to_exit_ = false;
      break;
    } else if (result_of_exit == kExit) {
      is_user_want_to_exit_ = true;
      break;
    } else {
      user_messenger_.ShowIncorrectInput();
    }
  }
}
