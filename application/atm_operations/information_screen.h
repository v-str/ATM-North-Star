#ifndef INFORMATION_SCREEN_H
#define INFORMATION_SCREEN_H

#include <sstream>
#include <string>

class InformationScreen {
 public:
  void DisplayLogin(const std::string& login) const;
  void DisplayPassword(const std::string& password) const;
  void DisplayCash(int cash) const;
  void DisplayCredit(int credit) const;
  void DisplayPayment(double payment) const;
  void DisplayCreditMonth(int credit_month) const;

  void DisplayLine(const std::string& info_title,
                   const std::string& info_line) const;

 private:
  template <typename T>
  void DisplayUserInformation(const std::string& info_title,
                              const T& value) const;
  template <typename T>
  static std::string ConvertToString(const T& value);

  static const int kNTimes = 45;
  static const int kSleep = 100;
};

template <typename T>
void InformationScreen::DisplayUserInformation(const std::string& info_title,
                                               const T& value) const {
  DisplayLine(info_title, ConvertToString(value));
}

template <typename T>
std::string InformationScreen::ConvertToString(const T& value) {
  std::stringstream stream;
  stream << value;
  return stream.str();
}

#endif  // INFORMATIONSCREEN_H
