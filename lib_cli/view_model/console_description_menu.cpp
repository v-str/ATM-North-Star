#include <console_description_menu.h>

void ConsoleDescriptionMenu::RunDescriptionMenu() {
  DiplayDemoMenuTitleOn();
  for (;;) {
    DisplayDemoSubMenu();
    if (user_want_to_exit_ || user_want_to_initial_menu_) {
      break;
    }
    DiplayDemoMenuTitleOff();
  }
}

void ConsoleDescriptionMenu::DisplayDemoSubMenu() {
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
  } else if (user_choice == kExitInitialMenu) {
    user_want_to_initial_menu_ = true;
  } else if (user_choice == kExit) {
    user_want_to_exit_ = true;
  } else {
    DemoUserMessenger::ShowIncorrectMenuInput();
    SuggestToExit();
  }
}

bool ConsoleDescriptionMenu::UserWantToInitialMenu() const {
  return user_want_to_initial_menu_;
}

bool ConsoleDescriptionMenu::UserWantToExitProgram() const {
  return user_want_to_exit_;
}

void ConsoleDescriptionMenu::DisplaySubmenu(
    DemoUserMessenger::MessageType message_type) {
  DemoUserMessenger::ShowMessage(message_type);
  SuggestToExit();
}

void ConsoleDescriptionMenu::SuggestToExit() {
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

void ConsoleDescriptionMenu::DiplayDemoMenuTitleOn() {
  DemoUserMessenger::ShowMessage(DemoUserMessenger::kWelcome);
  DemoUserMessenger::ShowDemoMenu(DemoUserMessenger::kNoClearScreen);
}

void ConsoleDescriptionMenu::DiplayDemoMenuTitleOff() {
  DemoUserMessenger::ShowDemoMenu(DemoUserMessenger::kCLearScreen);
}
