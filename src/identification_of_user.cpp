#include "identification_of_user.h"

static const int kMaxLenghtOfLogin = 21;
static const int kMaxLenghtOfPassword = 4;

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
  return account_info_.password_.length() == kMaxLenghtOfPassword;
}

void IdentificationOfUser::NoticeAboutIncorrectLogin() const {
  user_messanger_.ShowIncorrectLoginMessage();
}

void IdentificationOfUser::NoticeAboutIncorrectPassword() const {
    user_messanger_.ShowIncorrectFormatPasswordMessage();
}

void IdentificationOfUser::ShowAccountInformation()
{
    user_messanger_.ShowAccountInfo(account_info_);
}

void IdentificationOfUser::NoticeAboutSuccessfulRegistration() {
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
