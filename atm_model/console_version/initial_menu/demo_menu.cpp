#include <demo_menu.h>

void cli::DemoMenu::RunDemoMenu() {
  DiplayDemoMenuWithTitle();
  for (;;) {
    DisplayDemoPointrBasedOnUserChoice();
    if (user_want_to_registrate_ || user_want_to_exit_) {
      break;
    }
    DemoUserMessenger::ShowDemoMenu(DemoUserMessenger::kCLearScreen);
  }
}

void cli::DemoMenu::UserWantToExitProgram() { user_want_to_exit_ = true; }

void cli::DemoMenu::DisplayDemoPointrBasedOnUserChoice() {
  int user_choice = user_input_.GetValueFromUser();
  if (user_choice == kAccountPoint) {
    DisplaySubmenu(DemoUserMessenger::kAccountInfo);
  } else if (user_choice == kRefillPoint) {
    DisplaySubmenu(DemoUserMessenger::kRefillInfo);
  } else if (user_choice == kCreditPoint) {
    DisplaySubmenu(DemoUserMessenger::kCreditInfo);
  } else if (user_choice == kWidthdrawalPoint) {
    DisplaySubmenu(DemoUserMessenger::kWithdrawalInfo);
  } else if (user_choice == kStatementPoint) {
    DisplaySubmenu(DemoUserMessenger::kStatementInfo);
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

bool cli::DemoMenu::UserWantToRegistrate() const {
  return user_want_to_registrate_;
}

bool cli::DemoMenu::UserWantToLogin() const { return user_want_to_login_; }

void cli::DemoMenu::DisplaySubmenu(
    DemoUserMessenger::MessageType message_type) {
  DemoUserMessenger::ShowMessage(message_type);
  SuggestToExit();
}

void cli::DemoMenu::LeadToRegistration() {
  user_want_to_exit_ = user_want_to_registrate_ = true;
}

void cli::DemoMenu::LeadToLogin() {
  user_want_to_exit_ = user_want_to_login_ = true;
}

void cli::DemoMenu::SuggestToExit() {
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

void cli::DemoMenu::DiplayDemoMenuWithTitle() {
  DemoUserMessenger::ShowMessage(DemoUserMessenger::kWelcome);
  DemoUserMessenger::ShowDemoMenu(DemoUserMessenger::kNoClearScreen);
}
