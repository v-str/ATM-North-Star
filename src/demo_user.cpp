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
  if (user_choice == kAccountSection) {
    DemoAccountInfo();
  } else if (user_choice == kRefillSection) {
    DemoRefill();
  } else if (user_choice == kCreditSection) {
    DemoCreditApp();
  } else if (user_choice == kWidthdrawalSection) {
    DemoWidthdrawal();
  } else if (user_choice == kStatementSection) {
    DemoStatement();
  } else if (user_choice == kExitSection) {
    UserWantToExitProgram();
  } else if (user_choice == kRegistrationSection) {
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


