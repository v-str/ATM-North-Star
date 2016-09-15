#include "user_identifier.h"

static const int kMaxLenghtOfLogin = 21;
static const int kMaxLenghtOfPassword = 4;

UserIdentifier::UserIdentifier() {}

void UserIdentifier::InitLogin(const UserIdentifier::string login) {
  account_info_.login_ = login;
}

void UserIdentifier::InitPassword(const UserIdentifier::string password) {
  account_info_.password_ = password;
}

void UserIdentifier::InitCash(const int cash) { account_info_.cash_ = cash; }

void UserIdentifier::InitCredit(const int credit) {
  account_info_.credit_ = credit;
}

void UserIdentifier::InitMonthlyPayment(const double monthly_payment) {
  account_info_.monthly_payment_ = monthly_payment;
}

void UserIdentifier::InitAmountOfCreditMonth(const int amount_credit_month) {
  account_info_.amount_of_credit_month_ = amount_credit_month;
}

int UserIdentifier::AddCash(const int sum) {
  return account_info_.cash_ += sum;
}

int UserIdentifier::DeductCashFromUser(const int sum) {
  return account_info_.cash_ -= sum;
}

int UserIdentifier::ReturnCash() const { return account_info_.cash_; }

int UserIdentifier::ReturnCredit() const { return account_info_.credit_; }

UserIdentifier::string UserIdentifier::ReturnLogin() const {
  return account_info_.login_;
}

UserIdentifier::string UserIdentifier::ReturnPassword() const {
  return account_info_.password_;
}

int UserIdentifier::ReturnAmountOfCreditMonth() const {
  return account_info_.amount_of_credit_month_;
}

int UserIdentifier::AssignACredit(const int sum_of_credit) {
  return account_info_.credit_ = sum_of_credit;
}

double UserIdentifier::AssignAMonthlyPayment(const double pay_per_month) {
  return account_info_.monthly_payment_ = pay_per_month;
}

bool UserIdentifier::IsCreditAvailable() {
  return ReturnCash() >= 1000;
}

void UserIdentifier::GetLogin() {
  cout << "\n\n\n\t\tLogin: ";

  user_messanger_.WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  user_messanger_.WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
  getline(cin, account_info_.login_);
  cin.sync();
}

void UserIdentifier::GetPassword() {
  cout << "\t\tPassword: XXXX\b\b\b\b";
  cin >> account_info_.password_;
  cin.sync();
}

bool UserIdentifier::IsNormalLogin() {
  return !account_info_.login_.empty() &&
         account_info_.login_.length() < kMaxLenghtOfLogin;
}

bool UserIdentifier::IsNormalPass() {
  return account_info_.password_.length() == kMaxLenghtOfPassword;
}

void UserIdentifier::NoticeAboutSuccessfulRegistration() {
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

void UserIdentifier::NoticeAboutIncorrectLogin() const {
  error_message_.NoticeAboutIncorrectLoginMessage();
}

void UserIdentifier::NoticeAboutIncorrectPassword() const {
  error_message_.NoticeAboutIncorrectFormatPasswordMessage();
}

UserIdentifier::string UserIdentifier::GetPasswordFromUser() {
  string password;
  cin >> password;
  utility_.IgnoreCinLine();
  return password;
}

void UserIdentifier::ShowAccountInformation() {
  user_messanger_.ShowAccountInfo(account_info_);
}
