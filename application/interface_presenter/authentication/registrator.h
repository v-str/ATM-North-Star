#ifndef REGISTRATOR_H
#define REGISTRATOR_H

#include <string>

#include <menu_input_handler.h>
#include <registration_handler.h>
#include <user_input_handler.h>

class Registrator {
 public:
  void RunRegistrationMenu();

 private:
  enum MenuItems { kSymbolQuit, kRegistration, kDigitQuit };

  void ProcessMenuUserInput();
  void RunRegistrationProcedure();

  void GetRegistratoinDataFromUser();

  void GetLoginStringFromUser();
  void GetPasswordStringFromUser();

  UserInputHandler user_input_;
  MenuInputHandler menu_input_;
  RegistrationHandler registration_handler_;

  std::string login_ = "user";
  std::string password_ = "password";

  bool user_want_to_registrate = false;
};

#endif  // REGISTRATOR_H
