#include <demo_menu.h>

void DemoMenu::RunDemoMenu() {
  DiplayDemoMenuTitleOn();
  for (;;) {
    DisplayDemoSubMenu();
    if (user_want_to_registrate_ || user_want_to_exit_ || user_want_to_login_) {
      break;
    }
    DiplayDemoMenuTitleOff();
  }
}

void DemoMenu::UserWantToExitProgram() { user_want_to_exit_ = true; }

void DemoMenu::DisplayDemoSubMenu() {
  int user_choice = user_input_.GetValueFromUser();
  if (user_choice == kAccount) {
    DisplaySubmenu(DemoUserMessenger::kAccountInfo);
  } else if (user_choice == kRefill) {
    DisplaySubmenu(DemoUserMessenger::kRefillInfo);
  } else if (user_choice == kCredit) {
    DisplaySubmenu(DemoUserMessenger::kCreditInfo);
  } else if (user_choice == kWidthdrawal) {
    DisplaySubmenu(DemoUserMessenger::kWithdrawalInfo);
  } else if (user_choice == kStatement) {
    DisplaySubmenu(DemoUserMessenger::kStatementInfo);
  } else if (user_choice == kLogin) {
    LeadToRegistration();
  } else if (user_choice == kRegistration) {
    LeadToRegistration();
  } else if (user_choice == kExit) {
    UserWantToExitProgram();
  } else {
    DemoUserMessenger::ShowIncorrectMenuInput();
    SuggestToExit();
  }
}

bool DemoMenu::UserWantToRegistrate() const { return user_want_to_registrate_; }

bool DemoMenu::UserWantToLogin() const { return user_want_to_login_; }

void DemoMenu::DisplaySubmenu(DemoUserMessenger::MessageType message_type) {
  DemoUserMessenger::ShowMessage(message_type);
  SuggestToExit();
}

void DemoMenu::LeadToRegistration() {
  user_want_to_exit_ = user_want_to_registrate_ = true;
}

void DemoMenu::LeadToLogin() {
  user_want_to_exit_ = user_want_to_login_ = true;
}

void DemoMenu::SuggestToExit() {
  DemoUserMessenger::SuggestExit();
  for (;;) {
    int result_of_exit = 0;
    result_of_exit = user_input_.GetValueFromUser();

    if (result_of_exit == kDemoMenu) {
      user_want_to_exit_ = false;
      break;
    } else if (result_of_exit == kExitProgram) {
      user_want_to_exit_ = true;
      break;
    } else {
      DemoUserMessenger::ShowIncorrectInput();
    }
  }
}

void DemoMenu::DiplayDemoMenuTitleOn() {
  DemoUserMessenger::ShowMessage(DemoUserMessenger::kWelcome);
  DemoUserMessenger::ShowDemoMenu(DemoUserMessenger::kNoClearScreen);
}

void DemoMenu::DiplayDemoMenuTitleOff() {
  DemoUserMessenger::ShowDemoMenu(DemoUserMessenger::kCLearScreen);
}
