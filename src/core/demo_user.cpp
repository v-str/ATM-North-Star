#include "demo_user.h"

void DemoUser::ShowDemoMode() {
  auto message_type = DemoMessanger::MessageType::kWelcome;
  demo_messenger_.ShowMessage(message_type);
  UserDecideToExit();
  if (user_want_to_exit_) {
    return;
  }
  for (;;) {
    demo_messenger_.ShowDemoMenuMessage();
    UserDecideToExit();
    if (user_want_to_exit_) {
      return;
    }
  }
}

bool DemoUser::UserWantToRegistrate() const { return user_want_to_registrate_; }

void DemoUser::UserWantToExitProgram() { SayGoodBye(); }

void DemoUser::UserDecideToExit() {
  int user_choice = input_.GetValueFromUser();
  if (user_choice == kAccountSection) {
    StartSection(DemoMessanger::MessageType::kAccountInfo);
  } else if (user_choice == kRefillSection) {
    StartSection(DemoMessanger::MessageType::kRefill);
  } else if (user_choice == kCreditSection) {
    StartSection(DemoMessanger::MessageType::kCreditApp);
  } else if (user_choice == kWidthdrawalSection) {
    StartSection(DemoMessanger::MessageType::kWithdrawal);
  } else if (user_choice == kStatementSection) {
    StartSection(DemoMessanger::MessageType::kStatement);
  } else if (user_choice == kExitSection) {
    UserWantToExitProgram();
  } else if (user_choice == kRegistrationSection) {
    StartRegistration();
  } else {
    demo_messenger_.ShowIncorrectInput();
    user_want_to_exit_ = input_.SuggestUserToExit();
  }
}

void DemoUser::StartSection(DemoMessanger::MessageType message_type) {
  demo_messenger_.ShowMessage(message_type);
  demo_messenger_.ShowSuggestionAboutExit();
  user_want_to_exit_ = input_.SuggestUserToExit();
}

void DemoUser::StartRegistration() { ForwardToRegistration(); }

void DemoUser::ForwardToRegistration() {
  user_want_to_registrate_ = true;
  user_want_to_exit_ = user_want_to_registrate_;
}

void DemoUser::SayGoodBye() { user_want_to_exit_ = true; }
