#include "program_launcher.h"

void ProgramLauncher::RunInitialScreen() {
  initial_messenger_.DisplayInitialScreen();
  size_t user_choice = user_input_.GetValueFromUser();

  RunInitialProgamMenu(user_choice);
}

void ProgramLauncher::RunInitialProgamMenu(const size_t user_choice) {
  RunInitialMenuOperation(user_choice);

  if (IsCorrectRegistration()) {
    RunMainProgramMenu();
  }

  EndProgram();
}

void ProgramLauncher::RunInitialMenuOperation(const size_t user_choice) {
  if (user_choice == kDemo) {
    RunDemoMode();
  } else if (user_choice == kRegistration) {
    RegistrateUser();
  } else {
    ShowIncorrectRegistration();
  }
}

void ProgramLauncher::RunDemoMode() {
  demo_mode_.ShowDemoMode();
  if (demo_mode_.UserWantToRegistrate()) {
    RegistrateUser();
  }
}

void ProgramLauncher::RegistrateUser() {
  registrator_.RegisterUser(atm_user_profile_);
}

void ProgramLauncher::RunMainProgramMenu() {
  do {
    user_messenger_.ShowMainMenu();
    ExecuteATMOperation(user_input_.GetValueFromUser());
  } while (!user_want_to_exit_);
}

void ProgramLauncher::ExecuteATMOperation(size_t user_choice) {
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

void ProgramLauncher::RunAccountInfo() {
  account_informator_.DisplayAccountInformation(&atm_user_profile_);
  GetExitResult();
}

void ProgramLauncher::RunRefill() {
  refill_.StartRefillOperation(&atm_user_profile_);
  GetExitResult();
}

void ProgramLauncher::RunCredit() {
  user_credit_.StartCreditOperation(&atm_user_profile_);
  GetExitResult();
}

void ProgramLauncher::RunWithdraw() {
  withdrawal_.WithdrawCashFromUser(&atm_user_profile_);
  GetExitResult();
}

void ProgramLauncher::RunStatement() {
  statement_.ShowStatement(&atm_user_profile_);
  GetExitResult();
}

void ProgramLauncher::GetExitResult() {
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

bool ProgramLauncher::IsCorrectRegistration() {
  return registrator_.IsCorrectRegistration();
}

void ProgramLauncher::EndProgram() { user_messenger_.WishAGoodDay(); }

void ProgramLauncher::ShowIncorrectRegistration() const {
  user_messenger_.ShowIncorrectRegisterData();
}
