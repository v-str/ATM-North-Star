#ifndef REGISTERMESSENGER_H
#define REGISTERMESSENGER_H

#include "text_editor.h"

class RegisterMessenger {
 public:
  void ShowRegistrationScreen() const;

 private:
  TextEditor text_editor_;
};

#endif  // REGISTERMESSENGER_H
