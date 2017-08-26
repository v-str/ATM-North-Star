#include <console_main_menu.h>

#include <main_menu_messenger.h>
#include <submenu_input_handler.h>

void ConsoleMainMenu::RunMainMenu() {
  MainMenuMessenger::ShowMainMenu();
  ProcessMenuUserInput();
}

void ConsoleMainMenu::ProcessMenuUserInput() {
  user_input_handler_ =
      std::unique_ptr<UserInputHandler>(new SubMenuInputHandler);
  int user_input = 0;
  for (;;) {
    user_input = user_input_handler_->GetDigitInputFromUser();
  }
}
