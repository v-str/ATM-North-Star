#include "account_informator.h"

#include <atm_user.h>
#include <user_data_converter.h>

std::string AccountInformator::login_ = "not specified";
std::string AccountInformator::cash_ = "not specified";
std::string AccountInformator::credit_sum_ = "not specified";
std::string AccountInformator::credit_term_ = "not specified";
std::string AccountInformator::interest_rate_ = "not specified";
std::string AccountInformator::monthly_payment_ = "not specified";

void AccountInformator::UpdataUserData(const AtmUser& user) {
  login_ = user.Login();
  cash_ = UserDataConverter::ConvertDataToString(user.Cash());
  credit_sum_ = UserDataConverter::ConvertDataToString(user.CreditSum());
  credit_term_ = UserDataConverter::ConvertDataToString(user.CreditTerm());
  interest_rate_ = UserDataConverter::ConvertDataToString(user.InterestRate());
  monthly_payment_ =
      UserDataConverter::ConvertDataToString(user.MonthlyPayment());
}

std::string AccountInformator::Login() { return login_; }

std::string AccountInformator::Cash() { return cash_; }

std::string AccountInformator::CreditSum() { return credit_sum_; }

std::string AccountInformator::CreditTerm() { return credit_term_; }

std::string AccountInformator::InterestRate() { return interest_rate_; }

std::string AccountInformator::MonthlyPayment() { return monthly_payment_; }
