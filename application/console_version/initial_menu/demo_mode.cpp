#include <demo_mode.h>

void DemoMode::RunDemoMode() {
  DemoUserMessenger::ShowMessage(DemoUserMessenger::MessageType::kWelcome);
  DemoUserMessenger::ShowDemoMenu();
  GetUserChoice();
  while (!user_want_to_exit_) {
    if (user_want_to_registrate_) {
      break;
    }
    DemoUserMessenger::ShowDemoMenuAgain();
    GetUserChoice();
  }
}

void DemoMode::UserWantToExitProgram() { user_want_to_exit_ = true; }

void DemoMode::GetUserChoice() {
  int user_choice = user_input_.GetValueFromUser();
  if (user_choice == kAccountPoint) {
    StartSection(DemoUserMessenger::kAccountInfo);
  } else if (user_choice == kRefillPoint) {
    StartSection(DemoUserMessenger::kRefill);
  } else if (user_choice == kCreditPoint) {
    StartSection(DemoUserMessenger::kCreditApp);
  } else if (user_choice == kWidthdrawalPoint) {
    StartSection(DemoUserMessenger::kWithdrawal);
  } else if (user_choice == kStatementPoint) {
    StartSection(DemoUserMessenger::kStatement);
  } else if (user_choice == kLoginPoint) {
    StartRegistration();
  } else if (user_choice == kRegistrationPoint) {
    StartRegistration();
  } else if (user_choice == kExitPoint) {
    UserWantToExitProgram();
  } else {
    DemoUserMessenger::ShowIncorrectMenuInput();
    GetExitResult();
  }
}

bool DemoMode::UserWantToRegistrate() const { return user_want_to_registrate_; }

void DemoMode::StartSection(DemoUserMessenger::MessageType message_type) {
  DemoUserMessenger::ShowMessage(message_type);
  GetExitResult();
}

void DemoMode::StartRegistration() { ForwardToRegistration(); }

void DemoMode::GetExitResult() {
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

void DemoMode::ForwardToRegistration() {
  user_want_to_registrate_ = true;
  user_want_to_exit_ = user_want_to_registrate_;
}
