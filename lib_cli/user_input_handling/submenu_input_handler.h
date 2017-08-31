#ifndef SUBMENU_INPUT_HANDLER_H
#define SUBMENU_INPUT_HANDLER_H

#include <user_input_handler.h>

#include <string>

class SubMenuInputHandler : public UserInputHandler {
 public:
  int GetDigitInputFromUser() override;

  int GetQuitResult();

 private:
  enum SubMenuItem { kMainMenu = 1, kDigitalQuit = 2, kStringQuit = 0 };

  bool IsContainQuitString(const std::string& user_string);
};

#endif  // SUBMENU_INPUT_HANDLER_H
