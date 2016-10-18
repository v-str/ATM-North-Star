#ifndef USER_IDENTIFIER_H
#define USER_IDENTIFIER_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;

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
  string login_ = "no_name";
  string password_ = "0000";

  static const int kMaxLenghtOfLogin = 21;
  static const int kMaxLenghtOfPassword = 4;
};

#endif  // USER_IDENTIFIER_H
