#ifndef MENU_INPUT_HANDLER_H
#define MENU_INPUT_HANDLER_H

#include <user_input_handler.h>

#include <string>

namespace cli {

class MenuInputHandler : public UserInputHandler {
 public:
  int GetDigitInputFromUser() override;

  bool GetQuitResult();

 private:
  bool IsContainQuitString(const std::string& user_string);

  int kQuit = 0;
  int kMainMenu = 1;
  int kSubMenuQuit = 2;
};
}

#endif  // MENU_INPUT_HANDLER_H
