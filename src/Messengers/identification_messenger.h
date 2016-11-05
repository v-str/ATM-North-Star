#ifndef IDENTIFICATION_MESSENGER_H
#define IDENTIFICATION_MESSENGER_H

#include "system_utility.h"

class IdentificationMessenger {
 public:
  void ShowInitialLoginText() const;
  void ShowInitialPasswordText() const;

 private:
  static const int kMaxLenghtOfLogin = 21;
  static const int kMaxLenghtOfPassword = 4;

  SystemUtility utility_;
};

#endif  // IDENTIFICATION_MESSENGER_H
