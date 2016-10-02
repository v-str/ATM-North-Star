#ifndef REGISTRATION_MESSENGER_H
#define REGISTRATION_MESSENGER_H

#include "iostream"

#include "system_utility.h"

using std::cout;

class RegistrationMessenger {
 public:
  void ShowRegistrationScreen() const;

 private:
  SystemUtility utility_;
};

#endif  // REGISTRATION_MESSENGER_H
