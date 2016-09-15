#include "user_identifier.h"

static const int kMaxLenghtOfLogin = 21;
static const int kMaxLenghtOfPassword = 4;

//==========
void UserIdentifier::SetCash(int cash) { cash_ = cash; }

void UserIdentifier::SetCredit(int credit) { credit_ = credit; }

void UserIdentifier::SetMonthlyPayment(double monthly_payment) {
  monthly_payment_ = monthly_payment;
}

void UserIdentifier::SetAmountOfCreditMonth(int amount_credit_month) {
  amount_of_credit_month_ = amount_credit_month;
}

int UserIdentifier::AddCash(int sum) { return cash_ += sum; }

int UserIdentifier::WithdrawCashFromUser(int amount) { return cash_ -= amount; }

int UserIdentifier::Cash() const { return cash_; }

int UserIdentifier::Credit() const { return credit_; }

int UserIdentifier::AmountOfCreditMonth() const {
  return amount_of_credit_month_;
}

int UserIdentifier::AssignACredit(int sum_of_credit) {
  return credit_ = sum_of_credit;
}

double UserIdentifier::AssignAMonthlyPayment(double pay_per_month) {
  return monthly_payment_ = pay_per_month;
}

bool UserIdentifier::IsCreditAvailable() { return Cash() >= 1000; }
//==========

void UserIdentifier::SetLogin(const string &login) { login_ = login; }

void UserIdentifier::SetPassword(const UserIdentifier::string &password) {
  password_ = password;
}

UserIdentifier::string UserIdentifier::Login() const { return login_; }

UserIdentifier::string UserIdentifier::Password() const { return password_; }

void UserIdentifier::GetLogin() {
  cout << "\n\n\n\t\tLogin: ";

  user_messanger_.WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  user_messanger_.WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
  getline(cin, login_);
  cin.sync();
}

void UserIdentifier::GetPassword() {
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

void UserIdentifier::ShowAccountInformation() {
  cout << "\t";
  user_messanger_.WriteSymbolsNTimes('-', 45);

  user_messanger_.WriteUserInfo("Login", login_);
  user_messanger_.WriteUserInfo("Password", password_);
  user_messanger_.WriteUserInfo("Balance", std::to_string(cash_));
  user_messanger_.WriteUserInfo("Credit", std::to_string(credit_));
  user_messanger_.WriteUserInfo("Monthly payment $",
                                std::to_string(monthly_payment_));
  user_messanger_.WriteUserInfo("Credit term",
                                std::to_string(amount_of_credit_month_));
}
