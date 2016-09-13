#include "user_identificator.h"

static const int kMaxLenghtOfLogin = 21;
static const int kMaxLenghtOfPassword = 4;

UserIdentificator::UserIdentificator() {}

UserIdentificator::UserIdentificator(const string &login) {
  account_info_.login_ = login;
}

void UserIdentificator::GetLogin() {
  cout << "\n\n\n\t\tLogin: ";

  user_messanger_.WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  user_messanger_.WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
  getline(cin, account_info_.login_);
  cin.sync();
}

void UserIdentificator::GetPassword() {
  cout << "\t\tPassword: XXXX\b\b\b\b";
  cin >> account_info_.password_;
  cin.sync();
}

bool UserIdentificator::IsNormalLogin() {
  return !account_info_.login_.empty() &&
         account_info_.login_.length() < kMaxLenghtOfLogin;
}

bool UserIdentificator::IsNormalPass() {
  return account_info_.password_.length() == kMaxLenghtOfPassword;
}

void UserIdentificator::NoticeAboutSuccessfulRegistration() {
  utility_.IgnoreCinLine();
  utility_.ClearScreen();
  cout << "\n\n\t\t------------------\n";
  utility_.WriteTextWithDelay("\t\t| Access allowed |");
  cout << "\t\t------------------\n";
  utility_.Sleep(1000);
  account_info_.credit_ = 0.0;
  account_info_.monthly_payment_ = 0.0;
  account_info_.amount_of_credit_month_ = 0;
}

void UserIdentificator::NoticeAboutIncorrectLogin() const {
  error_.NoticeAboutIncorrectLoginMessage();
}

void UserIdentificator::NoticeAboutIncorrectPassword() const {
  error_.NoticeAboutIncorrectFormatPasswordMessage();
}

UserIdentificator::string UserIdentificator::GetPasswordFromUser() {
  string password;
  cin >> password;
  utility_.IgnoreCinLine();
  return password;
}

void UserIdentificator::ShowAccountInformation() {
  user_messanger_.ShowAccountInfo(account_info_);
}
