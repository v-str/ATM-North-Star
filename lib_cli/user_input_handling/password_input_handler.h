#ifndef PASSWORD_INPUT_HANDLER_H
#define PASSWORD_INPUT_HANDLER_H

#include <string>

class PasswordInputHandler {
 public:
  static std::string GetPassword();

 private:
  static void SetEcho(bool enable = false);

  static std::string kPassword;
};

#endif  // PASSWORD_INPUT_HANDLER_H
