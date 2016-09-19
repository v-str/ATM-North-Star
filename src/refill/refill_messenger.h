#ifndef REFILL_MESSENGER_H
#define REFILL_MESSENGER_H

#include <string>
#include "iostream"

#include "system_utility.h"

using std::cout;
using std::cin;

class RefillMessenger {
  using string = std::string;

 public:
  void ShowNotifyAboutCash() const;
  void ShowUserBalance(const int balance) const;
  void WriteUserInfo(const string &info_title, const string &value) const;

 private:
  SystemUtility utility_;
};

#endif  // REFILL_MESSENGER_H
