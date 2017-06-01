#ifndef QUIT_MENU_HANDLER_H
#define QUIT_MENU_HANDLER_H

#include <user_input_handler.h>

#include <string>

class QuitMenuHandler : public UserInputHandler {
 public:
  int GetDigitInputFromUser() override;

  bool GetQuitResult();

 private:
  bool IsContainQuitString(const std::string& user_string);

  int kQuit = 0;
  int kMainMenu = 1;
  int kSubMenuQuit = 2;
};

#endif  // QUIT_MENU_HANDLER_H
