#include "console_launcher.h"

void ConsoleLauncher::RunInitialScreen() {
  initial_messenger_.DisplayInitialScreen();
  int user_choice = user_input_.GetValueFromUser();

  InitialProgamMenu(user_choice);
}

void ConsoleLauncher::InitialProgamMenu(int user_choice) {
  InitialMenuOperation(user_choice);

  if (IsCorrectRegistration()) {
    MainProgramMenu();
  }

  EndProgram();
}

void ConsoleLauncher::InitialMenuOperation(int user_choice) {
  if (user_choice == kDemo) {
    DemoMenu();
  } else if (user_choice == kRegistration) {
    RegistrateUser();
  } else {
    ShowIncorrectRegistration();
  }
}

void ConsoleLauncher::DemoMenu() {
  demo_mode_.ShowDemoMode();
  if (demo_mode_.UserWantToRegistrate()) {
    RegistrateUser();
  }
}

void ConsoleLauncher::RegistrateUser() { registrator_.RegisterUser(user_); }

void ConsoleLauncher::MainProgramMenu() {
  do {
    user_messenger_.ShowMainMenu();
    ATMOperation(user_input_.GetValueFromUser());
  } while (!user_want_to_exit_);
}

void ConsoleLauncher::ATMOperation(int user_choice) {
  if (user_choice == kAccount) {
    AccountInfoMenu();
  } else if (user_choice == kRefill) {
    RefillMenu();
  } else if (user_choice == kCredit) {
    CreditMenu();
  } else if (user_choice == kWidthdrawal) {
    WithdrawMenu();
  } else if (user_choice == kStatement) {
    StatementMenu();
  } else if (user_choice == kExitProgram) {
    user_messenger_.AskToExit();
    SuggestToExit();
  } else {
    user_messenger_.ShowIncorrectMainMenuInput();
    user_want_to_exit_ = false;
  }
}

void ConsoleLauncher::AccountInfoMenu() {
  account_informator_.DisplayAccountInformation(&user_);
  SuggestToExit();
}

void ConsoleLauncher::RefillMenu() {
  refill_.StartRefillOperation(&user_);
  SuggestToExit();
}

void ConsoleLauncher::CreditMenu() {
  user_credit_.StartCreditOperation(&user_);
  SuggestToExit();
}

void ConsoleLauncher::WithdrawMenu() {
  withdrawal_.WithdrawCashFromUser(&user_);
  SuggestToExit();
}

void ConsoleLauncher::StatementMenu() {
  statement_.ShowStatement(&user_);
  SuggestToExit();
}

void ConsoleLauncher::SuggestToExit() {
  user_messenger_.SuggestToExit();
  for (;;) {
    int result_of_exit = 0;
    result_of_exit = user_input_.GetValueFromUser();

    if (result_of_exit == kMainMenu) {
      user_want_to_exit_ = false;
      break;
    } else if (result_of_exit == kExit) {
      user_want_to_exit_ = true;
      break;
    } else {
      user_messenger_.ShowIncorrectInput();
    }
  }
}

bool ConsoleLauncher::IsCorrectRegistration() const {
  return registrator_.IsCorrectRegistration();
}

void ConsoleLauncher::EndProgram() const { user_messenger_.WishAGoodDay(); }

void ConsoleLauncher::ShowIncorrectRegistration() const {
  user_messenger_.ShowIncorrectRegisterData();
}
