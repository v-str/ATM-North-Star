#include "identification_of_user.h"

static const int kMinimalSumForCredit = 1000;

static const int kMaxLenghtOfLogin = 21;

IdentificationOfUser::IdentificationOfUser() {}

IdentificationOfUser::IdentificationOfUser(const string &login) {
  account_info_.login_ = login;
}

void IdentificationOfUser::GetLogin() {
  cout << "\n\n\n\t\tLogin: ";

  user_messanger_.WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  user_messanger_.WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
  getline(cin, account_info_.login_);
  cin.sync();
}

void IdentificationOfUser::GetPassword() {
  cout << "\t\tPassword: XXXX\b\b\b\b";
  cin >> account_info_.password_;
  cin.sync();
}

bool IdentificationOfUser::IsNormalLogin() {
  return !account_info_.login_.empty() &&
         account_info_.login_.length() < kMaxLenghtOfLogin;
}

bool IdentificationOfUser::IsNormalPass() {
  return account_info_.password_.length() == 4;
}

void IdentificationOfUser::NoticeAboutIncorrectLogin() const {
  user_messanger_.ShowIncorrectLoginMessage();
}

void IdentificationOfUser::NoticeAboutIncorrectPassword() const {
     user_messanger_.ShowIncorrectFormatPasswordMessage();
}
