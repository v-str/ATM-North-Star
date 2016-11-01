#ifndef REGISTERMESSENGER_H
#define REGISTERMESSENGER_H

#include "system_utility.h"

class RegisterMessenger {
 public:
  void ShowRegistrationScreen() const;

 private:
  SystemUtility utility_;
};

#endif  // REGISTERMESSENGER_H
