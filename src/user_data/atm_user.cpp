#include "atm_user.h"

void AtmUser::SetLogin(const std::string& login) {
  identification_data_.SetLogin(login);
}

void AtmUser::SetPassword(const std::string& password) {
  identification_data_.SetPassword(password);
}

void AtmUser::SetCash(int cash) { cash_operator_.SetCash(cash); }

void AtmUser::SetCreditData(const CreditData& credit_data) {
  credit_data_ = credit_data;
}

std::string AtmUser::Login() const { return identification_data_.Login(); }

std::string AtmUser::Password() const {
  return identification_data_.Password();
}

int AtmUser::Cash() const { return cash_operator_.Cash(); }

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
