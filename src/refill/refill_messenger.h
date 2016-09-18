#ifndef REFILL_MESSENGER_H
#define REFILL_MESSENGER_H

#include "iostream"

#include "system_utility.h"

using std::cout;

class RefillMessenger {
 public:
  void ShowNotifyAboutCash() const;

 private:
  SystemUtility utility_;
};

#endif  // REFILL_MESSENGER_H
