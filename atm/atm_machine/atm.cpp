#include "atm.h"

#include <account_informator.h>
#include <refill.h>
#include <user_registrator.h>
#include <withdrawal.h>

void Atm::RegisterUser(const std::string& login, const std::string& password) {
  UserRegistrator::RegisterUser(&user_, login, password);
}

std::string Atm::AccountInfo(Atm::AccountData account_data) {
  AccountInformator::UpdataUserData(user_);
  switch (account_data) {
    case kLogin:
      return AccountInformator::Login();
    case kCash:
      return AccountInformator::Cash();
    case kCreditSum:
      return AccountInformator::CreditSum();
    case kCreditTerm:
      return AccountInformator::CreditTerm();
    case kInterestRate:
      return AccountInformator::InterestRate();
    case kMonthlyPayment:
      return AccountInformator::MonthlyPayment();
  }
}

void Atm::RefillCash(int refill_cash) {
  Refill::RefillCash(&user_, refill_cash);
}

bool Atm::WithdrawCash(int withdrawal_cash) {
  if (IsWithdrawalAcceptable(withdrawal_cash)) {
    Withdrawal::WithdrawCashFrom(&user_, withdrawal_cash);
    return true;
  }
  return false;
}

std::string Atm::Statement() {
  AccountInformator::UpdataUserData(user_);
  return AccountInformator::Cash();
}

bool Atm::IsWithdrawalAcceptable(int withdrawal_sum) const {
  return user_.Cash() >= withdrawal_sum;
}
