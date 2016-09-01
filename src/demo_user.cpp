#include "demo_user.h"

#include <iostream>
#include <limits>
#include <string>

#include "demo_message_set.h"
#include "system_utility.h"

using std::cin;
using std::cout;
using std::string;

void DemoUser::ShowDemoMode() {
  ClearScreen();
  ShowWelcomeDemoMessage();

  for (;;) {
    ShowDemoMenu();
    if (UserDecideToExit()) {
      break;
    }
    ClearScreen();
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
  ClearScreen();
  ShowDemoAccountInfoMsg();
  return user_input_.SuggestUserToExit();
}

bool DemoUser::UserWantToRegistrate() const { return user_want_to_registrate_; }

bool DemoUser::UserWantToExitProgram() const {
  user_input_.ShowExitMessage();
  return true;
}

bool DemoUser::StartRegistration() {
  user_want_to_registrate_ = true;
  return user_want_to_registrate_;
}

bool DemoUser::DemoRefill() const {
  ClearScreen();
  ShowInfoAboutRefillMsg();
  return user_input_.SuggestUserToExit();
}

bool DemoUser::DemoCreditApp() const {
  ShowDemoCreditAppMsg();
  return user_input_.SuggestUserToExit();
}

bool DemoUser::DemoWidthdrawal() const {
  ShowDemoWidthdrawalMsg();
  return user_input_.SuggestUserToExit();
}

bool DemoUser::DemoStatement() const {
  ShowDemoStatementMsg();
  return user_input_.SuggestUserToExit();
}
