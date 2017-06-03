#ifndef REGISTRATOR_H
#define REGISTRATOR_H

#include <string>

#include <authentication_handler.h>
#include <menu_input_handler.h>
#include <user_input_handler.h>

namespace cli {

class Registrator {
 public:
  void RunRegistrationMenu();

 private:
  enum RegistrationMenuPoints { kSymbolQuit, kStartRegistration, kDigitQuit };

  void ConfirmRegistration();
  void RunRegistrationProcedure();

  void GetRegistratoinDataFromUser();

  void GetLoginStringFromUser();
  void GetPasswordStringFromUser();

  UserInputHandler user_input_;
  MenuInputHandler menu_input_;
  AuthenticationHandler authenticaton_handler_;

  std::string login_ = "user";
  std::string password_ = "password";

  bool user_want_to_registrate = false;
};
}

#endif  // REGISTRATOR_H
