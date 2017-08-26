#include <atm_interactor.h>

#include <account_informator.h>
#include <atm_user.h>
#include <refill.h>
#include <user_registrator.h>
#include <withdrawal.h>

AtmUser* AtmInteractor::user_ = nullptr;

AtmInteractor::~AtmInteractor() { delete user_; }

void AtmInteractor::RegisterUser(const std::string& login,
                                 const std::string& password) {
  CheckOnUserExisting();

  UserRegistrator::RegisterUser(user_, login, password);
}

std::string AtmInteractor::AccountInfo(
    AtmInteractor::AccountData account_data) {
  AccountInformator::UpdataUserData(*user_);
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

void AtmInteractor::RefillCash(int refill_cash) {
  Refill::RefillCash(user_, refill_cash);
}

bool AtmInteractor::WithdrawCash(int withdrawal_cash) {
  if (IsWithdrawalAcceptable(withdrawal_cash)) {
    Withdrawal::WithdrawCashFrom(user_, withdrawal_cash);
    return true;
  }
  return false;
}

std::string AtmInteractor::Statement() {
  AccountInformator::UpdataUserData(*user_);
  return AccountInformator::Cash();
}

void AtmInteractor::ResetData() { user_->ResetData(); }

void AtmInteractor::CheckOnUserExisting() {
  if (user_ != nullptr) {
    delete user_;
  } else {
    user_ = new AtmUser;
  }
}

bool AtmInteractor::IsWithdrawalAcceptable(int withdrawal_sum) {
  return user_->Cash() >= withdrawal_sum;
}
