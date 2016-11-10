#ifndef IDENTIFICATION_MESSENGER_H
#define IDENTIFICATION_MESSENGER_H

#include "text_editor.h"

class IdentificationMessenger {
 public:
  void ShowInitialLoginText() const;
  void ShowInitialPasswordText() const;

 private:
  static const int kMaxLenghtOfLogin = 21;
  static const int kMaxLenghtOfPassword = 4;

  TextEditor text_editor_;
};

#endif  // IDENTIFICATION_MESSENGER_H
