#ifndef INFORMATION_SCREEN_H
#define INFORMATION_SCREEN_H

#include <string>

#include "account_messenger.h"
#include "cash_operator.h"
#include "system_utility.h"
#include "user_identifier.h"

using std::cout;

class InformationScreen {
 public:
  void DisplayUserInformation(const std::string &info_title,
                              const std::string &value) const;

  void DisplayStrip();

  void DisplayLogin(const std::string &login) const;

 private:
  AccountMessenger account_messenger_;
  SystemUtility utility_;

  static const int kNTimes = 45;
  static const int kSleep = 100;
};

#endif  // INFORMATIONSCREEN_H
