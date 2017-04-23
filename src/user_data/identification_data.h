#ifndef IDENTIFICATION_DATA_H
#define IDENTIFICATION_DATA_H

#include <string>

class IdentificationData {
 public:
  void SetLogin(const std::string &login);
  void SetPassword(const std::string &password);

  std::string GetLogin() const;
  std::string GetPassword() const;

  bool IsNormalLogin();
  bool IsNormalPass();

 private:
  static const int kMaxLenghtOfLogin = 21;
  static const int kMaxLenghtOfPassword = 4;

  std::string login_ = "no_name";
  std::string password_ = "0000";
};

#endif  // IDENTIFICATION_DATA_H
