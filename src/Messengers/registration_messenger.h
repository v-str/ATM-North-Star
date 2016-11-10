#ifndef REGISTRATION_MESSENGER_H
#define REGISTRATION_MESSENGER_H

#include "text_editor.h"

class RegistrationMessenger {
 public:
  void ShowRegistrationScreen() const;

 private:
  TextEditor text_editor_;
};

#endif  // REGISTRATION_MESSENGER_H
