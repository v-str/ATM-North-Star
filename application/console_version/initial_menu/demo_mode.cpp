#include <demo_mode.h>

void DemoMode::RunDemoMode() {
  DemoUserMessenger::ShowMessage(DemoUserMessenger::kWelcome);
  DemoUserMessenger::ShowDemoMenu(DemoUserMessenger::kNoClearScreen);
  GetUserChoice();
  while (!user_want_to_exit_) {
    if (user_want_to_registrate_) {
      break;
    }
    DemoUserMessenger::ShowDemoMenu(DemoUserMessenger::kCLearScreen);
    GetUserChoice();
  }
}

void DemoMode::UserWantToExitProgram() { user_want_to_exit_ = true; }

void DemoMode::GetUserChoice() {
  int user_choice = user_input_.GetValueFromUser();
  if (user_choice == kAccountPoint) {
    ShowSubmenu(DemoUserMessenger::kAccountInfo);
  } else if (user_choice == kRefillPoint) {
    ShowSubmenu(DemoUserMessenger::kRefillInfo);
  } else if (user_choice == kCreditPoint) {
    ShowSubmenu(DemoUserMessenger::kCreditInfo);
  } else if (user_choice == kWidthdrawalPoint) {
    ShowSubmenu(DemoUserMessenger::kWithdrawalInfo);
  } else if (user_choice == kStatementPoint) {
    ShowSubmenu(DemoUserMessenger::kStatementInfo);
  } else if (user_choice == kLoginPoint) {
    LeadToRegistration();
  } else if (user_choice == kRegistrationPoint) {
    LeadToRegistration();
  } else if (user_choice == kExitPoint) {
    UserWantToExitProgram();
  } else {
    DemoUserMessenger::ShowIncorrectMenuInput();
    SuggestToExit();
  }
}

bool DemoMode::UserWantToRegistrate() const { return user_want_to_registrate_; }

bool DemoMode::UserWantToLogin() const { return user_want_to_login_; }

void DemoMode::ShowSubmenu(DemoUserMessenger::MessageType message_type) {
  DemoUserMessenger::ShowMessage(message_type);
  SuggestToExit();
}

void DemoMode::LeadToRegistration() {
  user_want_to_exit_ = user_want_to_registrate_ = true;
}

void DemoMode::LeadToLogin() {
  user_want_to_exit_ = user_want_to_login_ = true;
}

void DemoMode::SuggestToExit() {
  DemoUserMessenger::SuggestExit();
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
      DemoUserMessenger::ShowIncorrectInput();
    }
  }
}
