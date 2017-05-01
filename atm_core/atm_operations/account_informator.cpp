#include "account_informator.h"

AccountInformator::AccountInformator()
    : login_("non specified"),
      cash_("non specified"),
      credit_sum_("non specified"),
      credit_term_("non specified"),
      interest_rate_("non specified"),
      monthly_payment_("non specified") {}

void AccountInformator::ConfigureAccountInformation(const AtmUser& user) {
  login_ = user.Login();
  cash_ = user.Cash();
  credit_sum_ = user.CreditSum();
  credit_term_ = user.CreditTerm();
  interest_rate_ = user.InterestRate();
  monthly_payment_ = user.MonthlyPayment();
}

std::string AccountInformator::Login() const { return login_; }

std::string AccountInformator::Cash() const { return cash_; }

std::string AccountInformator::CreditSum() const { return credit_sum_; }

std::string AccountInformator::CreditTerm() const { return credit_term_; }

std::string AccountInformator::InterestRate() const { return interest_rate_; }

std::string AccountInformator::MonthlyPayment() const {
  return monthly_payment_;
}
