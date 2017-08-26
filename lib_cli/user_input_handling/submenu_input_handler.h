#ifndef SUBMENU_INPUT_HANDLER_H
#define SUBMENU_INPUT_HANDLER_H

#include <user_input_handler.h>

#include <string>

class SubMenuInputHandler : public UserInputHandler {
 public:
  int GetDigitInputFromUser() override;

  bool GetQuitResult();

 private:
  bool IsContainQuitString(const std::string& user_string);

  int kQuit = 0;
  int kMainMenu = 1;
  int kSubMenuQuit = 2;
};

#endif  // SUBMENU_INPUT_HANDLER_H
