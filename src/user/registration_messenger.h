#ifndef REGISTRATION_MESSENGER_H
#define REGISTRATION_MESSENGER_H

#include "iostream"

#include "system_utility.h"

using std::cout;

class RegistrationMessenger {
 public:
  void ShowRegistrationScreen() const;
  void ShowInitialLoginText() const;
  void ShowInitialPasswordText() const;

 private:
  static const int kMaxLenghtOfLogin = 21;
  static const int kMaxLenghtOfPassword = 4;

  SystemUtility utility_;
};

#endif  // REGISTRATION_MESSENGER_H
