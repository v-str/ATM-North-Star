#include "cash_operator.h"

void CashOperator::SetCash(int cash) { cash_ = cash; }

void CashOperator::SetCredit(int credit) { credit_ = credit; }

void CashOperator::SetMonthlyPayment(double monthly_payment) {
  monthly_payment_ = monthly_payment;
}

void CashOperator::SetAmountOfCreditMonth(int amount_credit_month) {
  amount_of_credit_month_ = amount_credit_month;
}

int CashOperator::GetCash() const { return cash_; }

int CashOperator::GetCredit() const { return credit_; }

double CashOperator::GetMonthlyPayment() const { return monthly_payment_; }

int CashOperator::GetAmountOfCreditMonth() const {
  return amount_of_credit_month_;
}

void CashOperator::AssignACredit(int sum_of_credit) { credit_ = sum_of_credit; }

bool CashOperator::IsCreditAvailable() const {
  return GetCash() >= kmininmal_sum_for_credit;
}

int CashOperator::WithdrawCashFromUser(int amount) { return cash_ -= amount; }

void CashOperator::AddCash(int sum_of_cash) { cash_ += sum_of_cash; }

void CashOperator::AssignAMonthlyPayment(double pay_per_month) {
  monthly_payment_ = pay_per_month;
}

bool CashOperator::IsCreditExist() const {
  return (credit_ > 0) ? true : false;
}
