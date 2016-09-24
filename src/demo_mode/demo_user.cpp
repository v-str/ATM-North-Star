#include "demo_user.h"

#include <iostream>
#include <limits>
#include <string>

void DemoUser::ShowDemoMode() {
  auto message_type = DemoUserMessanger::MessageType::kWelcome;
  demo_messanger_.ShowMessage(message_type);
  UserDecideToExit();
  if (user_want_to_exit_) {
    return;
  }
  for (;;) {
    demo_messanger_.ShowDemoMenuMessage();
    UserDecideToExit();
    if (user_want_to_exit_) {
      return;
    }
  }
}

bool DemoUser::UserWantToRegistrate() { return user_want_to_registrate_; }

void DemoUser::UserWantToExitProgram() { SayGoodBye(); }

void DemoUser::UserDecideToExit() {
  int user_choice = user_input_.GetChoiceFromUser();
  if (user_choice == kAccountSection) {
    StartSection(DemoUserMessanger::MessageType::kAccountInfo);
  } else if (user_choice == kRefillSection) {
    StartSection(DemoUserMessanger::MessageType::kRefill);
  } else if (user_choice == kCreditSection) {
    StartSection(DemoUserMessanger::MessageType::kCreditApp);
  } else if (user_choice == kWidthdrawalSection) {
    StartSection(DemoUserMessanger::MessageType::kWithdrawal);
  } else if (user_choice == kStatementSection) {
    StartSection(DemoUserMessanger::MessageType::kStatement);
  } else if (user_choice == kExitSection) {
    UserWantToExitProgram();
  } else if (user_choice == kRegistrationSection) {
    StartRegistration();
  } else {
    user_input_.ShowIncorrectMessage();
  }
}

void DemoUser::StartSection(DemoUserMessanger::MessageType message_type) {
  demo_messanger_.ShowMessage(message_type);
  user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void DemoUser::ForwardToRegistration() {
  user_want_to_registrate_ = true;
  user_want_to_exit_ = user_want_to_registrate_;
}

void DemoUser::StartRegistration() { ForwardToRegistration(); }

void DemoUser::SayGoodBye() {
  user_input_.ShowExitMessage();
  user_want_to_exit_ = true;
}
