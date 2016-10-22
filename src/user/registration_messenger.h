#ifndef REGISTRATION_MESSENGER_H
#define REGISTRATION_MESSENGER_H

#include "system_utility.h"

class RegistrationMessenger {
 public:
  void ShowRegistrationScreen() const;

 private:
  SystemUtility utility_;
};

#endif  // REGISTRATION_MESSENGER_H
