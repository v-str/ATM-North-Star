#include "account_informator.h"

AccountInformator::AccountInformator()
    : login_("non specified"),
      cash_("non specified"),
      credit_sum_("non specified"),
      credit_term_("non specified"),
      interest_rate_("non specified"),
      monthly_payment_("non specified") {}

void AccountInformator::UpdataUserData(const AtmUser& user) {
  login_ = user.Login();
  cash_ = std::to_string(user.Cash());
  credit_sum_ = std::to_string(user.CreditSum());
  credit_term_ = std::to_string(user.CreditTerm());
  interest_rate_ = std::to_string(user.InterestRate());
  monthly_payment_ = std::to_string(user.MonthlyPayment());
}

std::string AccountInformator::Login() const { return login_; }

std::string AccountInformator::Cash() const { return cash_; }

std::string AccountInformator::CreditSum() const { return credit_sum_; }

std::string AccountInformator::CreditTerm() const { return credit_term_; }

std::string AccountInformator::InterestRate() const { return interest_rate_; }

std::string AccountInformator::MonthlyPayment() const {
  return monthly_payment_;
}
