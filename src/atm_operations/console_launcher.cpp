#include "console_launcher.h"

void ConsoleLauncher::RunInitialScreen() {
  initial_messenger_.DisplayInitialScreen();
  size_t user_choice = user_input_.GetValueFromUser();

  RunInitialProgamMenu(user_choice);
}

void ConsoleLauncher::RunInitialProgamMenu(const size_t user_choice) {
  RunInitialMenuOperation(user_choice);

  if (IsCorrectRegistration()) {
    RunMainProgramMenu();
  }

  EndProgram();
}

void ConsoleLauncher::RunInitialMenuOperation(const size_t user_choice) {
  if (user_choice == kDemo) {
    RunDemoMode();
  } else if (user_choice == kRegistration) {
    RegistrateUser();
  } else {
    ShowIncorrectRegistration();
  }
}

void ConsoleLauncher::RunDemoMode() {
  demo_mode_.ShowDemoMode();
  if (demo_mode_.UserWantToRegistrate()) {
    RegistrateUser();
  }
}

void ConsoleLauncher::RegistrateUser() {
  registrator_.RegisterUser(atm_user_profile_);
}

void ConsoleLauncher::RunMainProgramMenu() {
  do {
    user_messenger_.ShowMainMenu();
    ExecuteATMOperation(user_input_.GetValueFromUser());
  } while (!user_want_to_exit_);
}

void ConsoleLauncher::ExecuteATMOperation(size_t user_choice) {
  if (user_choice == kAccount) {
    RunAccountInfo();
  } else if (user_choice == kRefill) {
    RunRefill();
  } else if (user_choice == kCredit) {
    RunCredit();
  } else if (user_choice == kWidthdrawal) {
    RunWithdraw();
  } else if (user_choice == kStatement) {
    RunStatement();
  } else if (user_choice == kExitProgram) {
    user_messenger_.AskToExit();
    GetExitResult();
  } else {
    user_messenger_.ShowIncorrectInput();
    user_want_to_exit_ = false;
  }
}

void ConsoleLauncher::RunAccountInfo() {
  account_informator_.DisplayAccountInformation(&atm_user_profile_);
  GetExitResult();
}

void ConsoleLauncher::RunRefill() {
  refill_.StartRefillOperation(&atm_user_profile_);
  GetExitResult();
}

void ConsoleLauncher::RunCredit() {
  user_credit_.StartCreditOperation(&atm_user_profile_);
  GetExitResult();
}

void ConsoleLauncher::RunWithdraw() {
  withdrawal_.WithdrawCashFromUser(&atm_user_profile_);
  GetExitResult();
}

void ConsoleLauncher::RunStatement() {
  statement_.ShowStatement(&atm_user_profile_);
  GetExitResult();
}

void ConsoleLauncher::GetExitResult() {
  user_messenger_.SuggestExit();
  int result_of_exit = 0;
  for (;;) {
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

bool ConsoleLauncher::IsCorrectRegistration() {
  return registrator_.IsCorrectRegistration();
}

void ConsoleLauncher::EndProgram() { user_messenger_.WishAGoodDay(); }

void ConsoleLauncher::ShowIncorrectRegistration() const {
  user_messenger_.ShowIncorrectRegisterData();
}
