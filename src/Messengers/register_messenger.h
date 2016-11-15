#ifndef REGISTERMESSENGER_H
#define REGISTERMESSENGER_H

#include "console_editor.h"

class RegisterMessenger {
 public:
  void ShowRegistrationScreen() const;

 private:
  ConsoleEditor text_editor_;
};

#endif  // REGISTERMESSENGER_H
