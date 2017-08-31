#include <submenu_input_handler.h>

#include <main_menu_messenger.h>

int SubMenuInputHandler::GetDigitInputFromUser() {
  std::string user_input = GetStringInputFromUser();
  if (IsContainQuitString(user_input)) {
    return kDigitalQuit;
  } else {
    return GetDigitsFromString(user_input);
  }
}

int SubMenuInputHandler::GetSubMenuInputResult() {
  MainMenuMessenger::ShowQuitMenu();
  int user_input = 0;
  for (;;) {
    user_input = GetDigitInputFromUser();
    if (user_input == kMainMenu) {
      break;
    }
    if (user_input == kDigitalQuit || user_input == kStringQuit) {
      user_input = kDigitalQuit;
      break;
    } else {
      MainMenuMessenger::ShowIncorrectInput();
    }
  }

  return user_input;
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
