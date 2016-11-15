#ifndef REGISTRATION_MESSENGER_H
#define REGISTRATION_MESSENGER_H

#include "console_editor.h"

class RegistrationMessenger {
 public:
  void ShowRegistrationScreen() const;

 private:
  ConsoleEditor text_editor_;
};

#endif  // REGISTRATION_MESSENGER_H
