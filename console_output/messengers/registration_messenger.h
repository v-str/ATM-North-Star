#ifndef REGISTRATION_MESSENGER_H
#define REGISTRATION_MESSENGER_H

#include "output_configuration/console_editor.h"

class RegistrationMessenger {
 public:
  void ShowRegistrationScreen();

 private:
  ConsoleEditor console_editor_;
};

#endif  // REGISTRATION_MESSENGER_H
