#include "atm_user.h"

AtmUser::AtmUser()
    : cash_operator_(new CashOperator), user_identifier_(new UserIdentifier) {}

void AtmUser::SetLogin(const std::string &login) {
  user_identifier_->SetLogin(login);
}

void AtmUser::SetPassord(const std::string &password) {
  user_identifier_->SetPassword(password);
}

void AtmUser::SetCash(int cash) { cash_operator_->SetCash(cash); }

void AtmUser::SetCredit(int credit) { cash_operator_->SetCredit(credit); }

void AtmUser::SetMonthlyPayment(double monthly_payment) {
  cash_operator_->SetMonthlyPayment(monthly_payment);
}

void AtmUser::SetAmountOfCreditMonth(int amount_credit_month) {
  cash_operator_->SetAmountOfCreditMonth(amount_credit_month);
}
