#ifndef IDENTIFICATION_MESSENGER_H
#define IDENTIFICATION_MESSENGER_H

#include "console_editor.h"

class IdentificationMessenger {
 public:
  void ShowInitialLoginText() const;
  void ShowInitialPasswordText() const;

 private:
  static const int kMaxLenghtOfLogin = 21;
  static const int kMaxLenghtOfPassword = 4;
  static const int kDelay = 50;

  ConsoleEditor console_editor_;
};

#endif  // IDENTIFICATION_MESSENGER_H
