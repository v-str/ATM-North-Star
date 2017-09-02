#include "account_informator.h"

#include <iomanip>
#include <sstream>

#include <atm_user.h>

std::string AccountInformator::login_ = "not specified";
std::string AccountInformator::cash_ = "not specified";
std::string AccountInformator::credit_sum_ = "not specified";
std::string AccountInformator::credit_term_ = "not specified";
std::string AccountInformator::interest_rate_ = "not specified";
std::string AccountInformator::monthly_payment_ = "not specified";

void AccountInformator::UpdataUserData(const AtmUser& user) {
  login_ = user.Login();

  std::stringstream ss;
  ss << std::fixed << std::setprecision(2) << user.Cash();

  cash_ = ss.str();
  credit_sum_ = std::to_string(user.CreditSum());
  monthly_payment_ = std::to_string(user.MonthlyPayment());
  interest_rate_ = std::to_string(user.InterestRate());
  credit_term_ = std::to_string(user.CreditTerm());
}

std::string AccountInformator::Login() { return login_; }

std::string AccountInformator::Cash() { return cash_; }

std::string AccountInformator::CreditSum() { return credit_sum_; }

std::string AccountInformator::CreditTerm() { return credit_term_; }

std::string AccountInformator::InterestRate() { return interest_rate_; }

std::string AccountInformator::MonthlyPayment() { return monthly_payment_; }
