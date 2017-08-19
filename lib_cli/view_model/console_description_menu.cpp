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
    DisplaySubmenu(DescriptionMessenger::kAccountInfo);
  } else if (user_choice == kRefill) {
    DisplaySubmenu(DescriptionMessenger::kRefillInfo);
  } else if (user_choice == kCredit) {
    DisplaySubmenu(DescriptionMessenger::kCreditInfo);
  } else if (user_choice == kWidthdrawal) {
    DisplaySubmenu(DescriptionMessenger::kWithdrawalInfo);
  } else if (user_choice == kStatement) {
    DisplaySubmenu(DescriptionMessenger::kStatementInfo);
  } else if (user_choice == kExitInitialMenu) {
    user_want_to_initial_menu_ = true;
  } else if (user_choice == kExit) {
    user_want_to_exit_ = true;
  } else {
    DescriptionMessenger::ShowIncorrectMenuInput();
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
    DescriptionMessenger::MessageType message_type) {
  DescriptionMessenger::ShowMessage(message_type);
  DisplayReturnMenu();
}

void ConsoleDescriptionMenu::DisplayReturnMenu() {
  DescriptionMessenger::ShowReturnMessage();
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
      DescriptionMessenger::ShowIncorrectInput();
    }
  }
}

void ConsoleDescriptionMenu::DiplayDemoMenuTitleOn() {
  DescriptionMessenger::ShowMessage(DescriptionMessenger::kWelcome);
  DescriptionMessenger::ShowDemoMenu(DescriptionMessenger::kNoClearScreen);
}

void ConsoleDescriptionMenu::DiplayDemoMenuTitleOff() {
  DescriptionMessenger::ShowDemoMenu(DescriptionMessenger::kCLearScreen);
}

void ConsoleDescriptionMenu::ResetManipulationFlags() {
  user_want_to_exit_ = false;
  user_want_to_initial_menu_ = false;
}
