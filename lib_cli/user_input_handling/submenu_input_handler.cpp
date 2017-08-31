#include <submenu_input_handler.h>

#include <main_menu_messenger.h>

int SubMenuInputHandler::GetDigitInputFromUser() {
  std::string user_input = GetStringInputFromUser();
  if (IsContainQuitString(user_input)) {
    return kQuit;
  } else {
    return GetDigitsFromString(user_input);
  }
}

bool SubMenuInputHandler::GetQuitResult() {
  MainMenuMessenger::ShowQuitMenu();
  bool quit = true;
  int user_choice = 0;
  for (;;) {
    user_choice = GetDigitInputFromUser();
    if (user_choice == kMainMenu) {
      quit = false;
      break;
    } else if (user_choice == kQuit || user_choice == kSubMenuQuit) {
      break;
    } else {
      MainMenuMessenger::ShowIncorrectInput();
    }
  }

  return quit;
}

bool SubMenuInputHandler::IsContainQuitString(const std::string& user_string) {
  if (user_string == "Quit" || user_string == "quit") {
    return true;
  }

  if (user_string == "Q" || user_string == "q") {
    return true;
  }

  return false;
}
