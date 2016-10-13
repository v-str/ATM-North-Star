#ifndef INFORMATION_SCREEN_H
#define INFORMATION_SCREEN_H

#include "account_messenger.h"
#include "system_utility.h"

using std::cout;

class InformationScreen {
 public:
  void DisplayStrip();

 private:
  AccountMessenger account_messenger_;
  SystemUtility utility_;

  static const int kNTimes = 45;
  static const int kSleep = 100;
};

#endif  // INFORMATIONSCREEN_H
