#include "demo_user.h"

#include <iostream>
#include <limits>
#include <string>

using std::cin;
using std::cout;
using std::string;

void DemoUser::ShowDemoMode() {
  demo_messanger_.ShowWelcomeDemoMessage();
  if (UserDecideToExit()) {
    return;
  }
  for (;;) {
    demo_messanger_.ShowDemoMenuMessage();
    if (UserDecideToExit()) {
      return;
    }
  }
}

bool DemoUser::UserDecideToExit() {
  int choice = user_input_.GetChoiceFromUser();
  if (choice == 1) {
    return DemoAccountInfo();
  } else if (choice == 2) {
    return DemoRefill();
  } else if (choice == 3) {
    return DemoCreditApp();
  } else if (choice == 4) {
    return DemoWidthdrawal();
  } else if (choice == 5) {
    return DemoStatement();
  } else if (choice == 6) {
    return UserWantToExitProgram();
  } else if (choice == 7) {
    return StartRegistration();
  } else {
    return user_input_.ShowIncorrectMessage();
  }
}

bool DemoUser::DemoAccountInfo() const {
  demo_messanger_.ShowDemoAccountInfoMessage();
  return user_input_.SuggestUserToExit();
}

bool DemoUser::DemoRefill() const {
  demo_messanger_.ShowInfoAboutRefillMessage();
  return user_input_.SuggestUserToExit();
}

bool DemoUser::DemoCreditApp() const {
  demo_messanger_.ShowDemoCreditAppMessage();
  return user_input_.SuggestUserToExit();
}

bool DemoUser::DemoWidthdrawal() const {
  demo_messanger_.ShowDemoWidthdrawalMessage();
  return user_input_.SuggestUserToExit();
}

bool DemoUser::DemoStatement() const {
  demo_messanger_.ShowDemoStatementMessage();
  return user_input_.SuggestUserToExit();
}

bool DemoUser::UserWantToExitProgram() const {
  user_input_.ShowExitMessage();
  return true;
}

bool DemoUser::StartRegistration() {
  user_want_to_registrate_ = true;
  return user_want_to_registrate_;
}

bool DemoUser::UserWantToRegistrate() const { return user_want_to_registrate_; }
