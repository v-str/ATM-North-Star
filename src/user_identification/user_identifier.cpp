#include "user_identifier.h"

static const int kMaxLenghtOfLogin = 21;
static const int kMaxLenghtOfPassword = 4;

void UserIdentifier::ShowLogin(const string &login) { login_ = login; }

void UserIdentifier::ShowPassword(const UserIdentifier::string &password) {
  password_ = password;
}

UserIdentifier::string UserIdentifier::GetLogin() const { return login_; }

UserIdentifier::string UserIdentifier::GetPassword() const { return password_; }

void UserIdentifier::ShowLogin() {
  cout << "\n\n\n\t\tLogin: ";

  user_messanger_.WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  user_messanger_.WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
  getline(cin, login_);
  cin.sync();
}

void UserIdentifier::ShowPassword() {
  cout << "\t\tPassword: XXXX\b\b\b\b";
  cin >> password_;
  cin.sync();
}

bool UserIdentifier::IsNormalLogin() {
  return !login_.empty() && login_.length() < kMaxLenghtOfLogin;
}

bool UserIdentifier::IsNormalPass() {
  return password_.length() == kMaxLenghtOfPassword;
}

UserIdentifier::string UserIdentifier::GetPasswordFromUser() {
  string password;
  cin >> password;
  utility_.IgnoreCinLine();
  return password;
}
