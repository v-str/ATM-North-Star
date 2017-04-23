#include "atm_user.h"

void AtmUser::SetLogin(const std::string& login) {
  identification_data_.SetLogin(login);
}

void AtmUser::SetPassword(const std::string& password) {
  identification_data_.SetPassword(password);
}

void AtmUser::SetCash(int cash) { cash_operator_.SetCash(cash); }

void AtmUser::SetCreditSum(int credit_sum) {
  credit_data_.SetCreditSum(credit_sum);
}

void AtmUser::SetMonthlyPayment(double monthly_payment) {
  credit_data_.SetMonthlyPayment(monthly_payment);
}

void AtmUser::SetCreditTerm(int months) { credit_data_.SetCreditTerm(months); }

std::string AtmUser::GetLogin() const {
  return identification_data_.GetLogin();
}

std::string AtmUser::GetPassword() const {
  return identification_data_.GetPassword();
}

int AtmUser::GetCash() const { return cash_operator_.GetCash(); }

int AtmUser::CreditSum() const { return credit_data_.CreditSum(); }

double AtmUser::MonthlyPayment() const { return credit_data_.MonthlyPayment(); }

int AtmUser::CreditTerm() const { return credit_data_.CreditTerm(); }

bool AtmUser::IsCreditExist() const { return credit_data_.IsCreditExist(); }

bool AtmUser::IsNormalLogin() { return identification_data_.IsNormalLogin(); }

bool AtmUser::IsNormalPass() { return identification_data_.IsNormalPass(); }

void AtmUser::AddCash(int sum_of_cash) { cash_operator_.AddCash(sum_of_cash); }

int AtmUser::WithdrawCash(int amount) {
  return cash_operator_.WithdrawCash(amount);
}
