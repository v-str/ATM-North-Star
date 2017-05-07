#include <demo_mode.h>

void DemoMode::ShowDemoMode() {
  DemoUserMessanger::ShowMessage(DemoUserMessanger::MessageType::kWelcome);
  DemoUserMessanger::ShowDemoMenu();
  GetUserDecision();
  while (!user_want_to_exit_) {
    if (user_want_to_registrate_) {
      break;
    }
    DemoUserMessanger::ShowDemoMenuAgain();
    GetUserDecision();
  }
}

bool DemoMode::UserWantToRegistrate() const { return user_want_to_registrate_; }

void DemoMode::UserWantToExitProgram() { SayGoodBye(); }

void DemoMode::GetUserDecision() {
  int user_choice = user_input_.GetValueFromUser();
  if (user_choice == kAccountSection) {
    StartSection(DemoUserMessanger::kAccountInfo);
  } else if (user_choice == kRefillSection) {
    StartSection(DemoUserMessanger::kRefill);
  } else if (user_choice == kCreditSection) {
    StartSection(DemoUserMessanger::kCreditApp);
  } else if (user_choice == kWidthdrawalSection) {
    StartSection(DemoUserMessanger::kWithdrawal);
  } else if (user_choice == kStatementSection) {
    StartSection(DemoUserMessanger::kStatement);
  } else if (user_choice == kExitSection) {
    UserWantToExitProgram();
  } else if (user_choice == kRegistrationSection) {
    StartRegistration();
  } else {
    DemoUserMessanger::ShowIncorrectMenuInput();
    GetExitResult();
  }
}

void DemoMode::StartSection(DemoUserMessanger::MessageType message_type) {
  DemoUserMessanger::ShowMessage(message_type);
  GetExitResult();
}

void DemoMode::StartRegistration() { ForwardToRegistration(); }

void DemoMode::GetExitResult() {
  DemoUserMessanger::SuggestExit();
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
      DemoUserMessanger::ShowIncorrectInput();
    }
  }
}

void DemoMode::ForwardToRegistration() {
  user_want_to_registrate_ = true;
  user_want_to_exit_ = user_want_to_registrate_;
}

void DemoMode::SayGoodBye() { user_want_to_exit_ = true; }
