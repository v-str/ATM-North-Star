#ifndef USER_IDENTIFIER_H
#define USER_IDENTIFIER_H

#include <string>

class UserIdentifier {
  using string = std::string;

 public:
  void SetLogin(const string &login);
  void SetPassword(const string &password);

  string GetLogin() const;
  string GetPassword() const;

  bool IsNormalLogin();
  bool IsNormalPass();

 private:
  static const int kMaxLenghtOfLogin = 21;
  static const int kMaxLenghtOfPassword = 4;

  string login_ = "no_name";
  string password_ = "0000";
};

#endif  // USER_IDENTIFIER_H
