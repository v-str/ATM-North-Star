#include "demo_user.h"

void DemoUser::ShowDemoMode() {
  demo_messenger_.ShowMessage(DemoMessanger::MessageType::kWelcome);
  demo_messenger_.ShowDemoMenu();
  GetUserDecision();
  do {
    if (user_want_to_registrate_) {
      break;
    }
    demo_messenger_.ShowDemoMenuAgain();
    GetUserDecision();
  } while (!user_want_to_exit_);
}

bool DemoUser::UserWantToRegistrate() const { return user_want_to_registrate_; }

void DemoUser::UserWantToExitProgram() { SayGoodBye(); }

void DemoUser::GetUserDecision() {
  int user_choice = user_input_.GetValueFromUser();
  if (user_choice == kAccountSection) {
    StartSection(DemoMessanger::kAccountInfo);
  } else if (user_choice == kRefillSection) {
    StartSection(DemoMessanger::kRefill);
  } else if (user_choice == kCreditSection) {
    StartSection(DemoMessanger::kCreditApp);
  } else if (user_choice == kWidthdrawalSection) {
    StartSection(DemoMessanger::kWithdrawal);
  } else if (user_choice == kStatementSection) {
    StartSection(DemoMessanger::kStatement);
  } else if (user_choice == kExitSection) {
    UserWantToExitProgram();
  } else if (user_choice == kRegistrationSection) {
    StartRegistration();
  } else {
    demo_messenger_.ShowIncorrectInput();
    user_want_to_exit_ = user_input_.SuggestUserToExit();
  }
}

void DemoUser::StartSection(DemoMessanger::MessageType message_type) {
  demo_messenger_.ShowMessage(message_type);
  GetExitResult();
}

void DemoUser::StartRegistration() { ForwardToRegistration(); }

void DemoUser::GetExitResult() {
  demo_messenger_.SuggestExit();
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
      demo_messenger_.ShowIncorrectInput();
    }
  }
}

void DemoUser::ForwardToRegistration() {
  user_want_to_registrate_ = true;
  user_want_to_exit_ = user_want_to_registrate_;
}

void DemoUser::SayGoodBye() { user_want_to_exit_ = true; }
