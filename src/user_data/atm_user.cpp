#include "atm_user.h"

AtmUser::AtmUser() {}

void AtmUser::SetLogin(const std::string& login) {
  user_identifier_.SetLogin(login);
}

void AtmUser::SetPassword(const std::string& password) {
  user_identifier_.SetPassword(password);
}

void AtmUser::SetCash(int cash) { cash_operator_.SetCash(cash); }

void AtmUser::SetCredit(int credit) { cash_operator_.SetCredit(credit); }

void AtmUser::SetMonthlyPayment(double monthly_payment) {
  cash_operator_.SetMonthlyPayment(monthly_payment);
}

void AtmUser::SetAmountOfCreditMonth(int amount_credit_month) {
  cash_operator_.SetAmountOfCreditMonth(amount_credit_month);
}

std::string AtmUser::GetLogin() const { return user_identifier_.GetLogin(); }

std::string AtmUser::GetPassword() const {
  return user_identifier_.GetPassword();
}

int AtmUser::GetCash() const { return cash_operator_.GetCash(); }

int AtmUser::GetCredit() const { return cash_operator_.GetCredit(); }

double AtmUser::GetMonthlyPayment() const {
  return cash_operator_.GetMonthlyPayment();
}

int AtmUser::GetAmountOfCreditMonth() const {
  return cash_operator_.GetAmountOfCreditMonth();
}

int AtmUser::WithdrawCash(int amount) {
  return cash_operator_.WithdrawCashFromUser(amount);
}

bool AtmUser::IsCreditAvailable() { return cash_operator_.IsCreditAvailable(); }

bool AtmUser::IsCreditExist() const { return cash_operator_.IsCreditExist(); }

bool AtmUser::IsNormalLogin() { return user_identifier_.IsNormalLogin(); }

bool AtmUser::IsNormalPass() { return user_identifier_.IsNormalPass(); }

void AtmUser::AddCash(int sum_of_cash) { cash_operator_.AddCash(sum_of_cash); }

void AtmUser::AssignAMonthlyPayment(double pay_per_month) {
  cash_operator_.AssignAMonthlyPayment(pay_per_month);
}
