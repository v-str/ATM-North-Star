#include "atm_user.h"

AtmUser::AtmUser()
    : cash_operator_(new CashOperator), user_identifier_(new UserIdentifier) {}

void AtmUser::set_login(const std::string &login) {
  user_identifier_->SetLogin(login);
}

void AtmUser::set_password(const std::string &password) {
  user_identifier_->SetPassword(password);
}

void AtmUser::set_cash(int cash) { cash_operator_->SetCash(cash); }

void AtmUser::set_credit(int credit) { cash_operator_->SetCredit(credit); }

void AtmUser::set_monthly_payment(double monthly_payment) {
  cash_operator_->SetMonthlyPayment(monthly_payment);
}

void AtmUser::set_amount_of_credit_month(int amount_credit_month) {
  cash_operator_->SetAmountOfCreditMonth(amount_credit_month);
}

std::string AtmUser::get_login() const { return user_identifier_->GetLogin(); }

std::string AtmUser::get_password() const {
  return user_identifier_->GetPassword();
}

int AtmUser::get_cash() const { return cash_operator_->GetCash(); }

int AtmUser::get_credit() const { return cash_operator_->GetCredit(); }

double AtmUser::get_monthly_payment() const {
  return cash_operator_->GetMonthlyPayment();
}

int AtmUser::get_amount_of_credit_month() const {
  return cash_operator_->GetAmountOfCreditMonth();
}

int AtmUser::get_assigned_credit(int sum_of_credit) {
  return cash_operator_->GetAssignACredit(sum_of_credit);
}

int AtmUser::withdraw_cash(int amount) {
  return cash_operator_->WithdrawCashFromUser(amount);
}

bool AtmUser::IsCreditAvailable() {
  return cash_operator_->IsCreditAvailable();
}

bool AtmUser::IsNormalLogin() { return user_identifier_->IsNormalLogin(); }

bool AtmUser::IsNormalPass() { return user_identifier_->IsNormalPass(); }

void AtmUser::AddCash(int sum_of_cash) { cash_operator_->AddCash(sum_of_cash); }

void AtmUser::AssignAMonthlyPayment(double pay_per_month) {
  cash_operator_->AssignAMonthlyPayment(pay_per_month);
}
