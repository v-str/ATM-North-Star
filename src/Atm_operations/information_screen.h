#ifndef INFORMATION_SCREEN_H
#define INFORMATION_SCREEN_H

#include <string>

#include "account_messenger.h"

class InformationScreen {
 public:
  void DisplayLogin(const std::string &login) const;
  void DisplayPassword(const std::string &password) const;
  void DisplayCash(int cash) const;
  void DisplayCredit(int credit) const;
  void DisplayPayment(double payment) const;
  void DisplayCreditMonth(int credit_month) const;

  void DisplayInfoLine(const std::string &info_title,
                       const std::string &info_line) const;

 private:
  template <typename T>
  void DisplayUserInformation(const std::string &info_title,
                              const T &value) const;
  template <typename T>
  std::string ConvertToString(const T &value) const;

  static const int kNTimes = 45;
  static const int kSleep = 100;

  AccountMessenger account_messenger_;
};

template <typename T>
void InformationScreen::DisplayUserInformation(const std::string &info_title,
                                               const T &value) const {
  DisplayInfoLine(info_title, ConvertToString(value));
}

template <typename T>
std::string InformationScreen::ConvertToString(const T &value) const {
  std::stringstream stream;
  stream << value;
  return stream.str();
}

#endif  // INFORMATIONSCREEN_H
