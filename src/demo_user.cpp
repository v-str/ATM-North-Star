#include "demo_user.h"

#include <iostream>
#include <limits>
#include <string>

bool DemoUser::UserWantToRegistrate() { return user_want_to_registrate_; }

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

void DemoUser::UserDecideToExit() {
  int user_choice = user_input_.GetChoiceFromUser();
  if (user_choice == 1) {
    DemoAccountInfo();
  } else if (user_choice == 2) {
    DemoRefill();
  } else if (user_choice == 3) {
    DemoCreditApp();
  } else if (user_choice == 4) {
    DemoWidthdrawal();
  } else if (user_choice == 5) {
    DemoStatement();
  } else if (user_choice == 6) {
    UserWantToExitProgram();
  } else if (user_choice == 7) {
    StartRegistration();
  } else {
    user_input_.ShowIncorrectMessage();
  }
}

void DemoUser::DemoAccountInfo() {
  StartAccountInfoSectionWithQuestionAboutExit();
}

void DemoUser::DemoRefill() { StartRefillSectionWithQuestionAboutExit(); }

void DemoUser::DemoCreditApp() { StartCreditSectionWithQuestionAboutExit(); }

void DemoUser::DemoWidthdrawal() {
  StartWidthdrawalInfoSectionWithQuestionAboutExit();
}

void DemoUser::DemoStatement() {
  StartStatementInfoSectionWithQuestionAboutExit();
}

void DemoUser::UserWantToExitProgram() { SayGoodBye(); }

void DemoUser::StartRegistration() { ForwardToRegistration(); }

void DemoUser::StartAccountInfoSectionWithQuestionAboutExit() {
  auto message_type = DemoUserMessanger::MessageType::kAccountInfo;
  demo_messanger_.ShowMessage(message_type);
  user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void DemoUser::StartRefillSectionWithQuestionAboutExit() {
  auto message_type = DemoUserMessanger::MessageType::kRefill;
  demo_messanger_.ShowMessage(message_type);
  user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void DemoUser::StartCreditSectionWithQuestionAboutExit() {
  auto message_type = DemoUserMessanger::MessageType::kCreditApp;
  demo_messanger_.ShowMessage(message_type);
  user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void DemoUser::StartWidthdrawalInfoSectionWithQuestionAboutExit() {
  auto message_type = DemoUserMessanger::MessageType::kWithdrawal;
  demo_messanger_.ShowMessage(message_type);
  user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void DemoUser::StartStatementInfoSectionWithQuestionAboutExit() {
  auto message_type = DemoUserMessanger::MessageType::kStatement;
  demo_messanger_.ShowMessage(message_type);
  user_want_to_exit_ = user_input_.SuggestUserToExit();
}

void DemoUser::SayGoodBye() {
  user_input_.ShowExitMessage();
  user_want_to_exit_ = true;
}

void DemoUser::ForwardToRegistration() {
  user_want_to_registrate_ = true;
  user_want_to_exit_ = user_want_to_registrate_;
}


