#include <console_description_menu.h>

void ConsoleDescriptionMenu::RunDescriptionMenu() {
  DiplayDemoMenuTitleOn();
  for (;;) {
    ResetManipulationFlags();
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
    DisplayReturnMenu();
  }
}

bool ConsoleDescriptionMenu::UserWantToInitialMenu() const {
  return user_want_to_initial_menu_;
}

bool ConsoleDescriptionMenu::IsUserWantToExitProgram() const {
  return user_want_to_exit_;
}

void ConsoleDescriptionMenu::DisplaySubmenu(
    DemoUserMessenger::MessageType message_type) {
  DemoUserMessenger::ShowMessage(message_type);
  DisplayReturnMenu();
}

void ConsoleDescriptionMenu::DisplayReturnMenu() {
  DemoUserMessenger::ShowReturnMessage();
  for (;;) {
    int input_result = 0;
    input_result = user_input_.GetValueFromUser();

    if (input_result == kInitialMenu) {
      user_want_to_initial_menu_ = true;
      break;
    } else if (input_result == kDemoMenu) {
      break;
    } else if (input_result == kExitProgram) {
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

void ConsoleDescriptionMenu::ResetManipulationFlags() {
  user_want_to_exit_ = false;
  user_want_to_initial_menu_ = false;
}
