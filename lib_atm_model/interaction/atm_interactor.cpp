#include <atm_interactor.h>

#include <account_informator.h>
#include <refill.h>
#include <user_registrator.h>
#include <withdrawal.h>

AtmUser AtmInteractor::user_;

void AtmInteractor::RegisterUser(const std::string& login,
                                 const std::string& password,
                                 const std::string& password_tooltip) {
  ResetData();

  UserRegistrator::RegisterUser(&user_, login, password, password_tooltip);
}

std::vector<std::string> AtmInteractor::AccountInfo() {
  AccountInformator::UpdataUserData(user_);

  std::vector<std::string> account_info;

  account_info.push_back(AccountInformator::Login());
  account_info.push_back(AccountInformator::Cash());

  return account_info;
}

void AtmInteractor::RefillCash(int refill_cash) {
  Refill::RefillCash(&user_, refill_cash);
}

void AtmInteractor::WithdrawCash(int withdrawal_cash) {
  Withdrawal::WithdrawCashFrom(&user_, withdrawal_cash);
}

void AtmInteractor::ResetData() { user_.ResetData(); }

bool AtmInteractor::IsPasswordCorrect(const std::string& password_string) {
  return password_string == user_.Password();
}

bool AtmInteractor::IsWithdrawalAcceptable(int withdrawal_sum) {
  return user_.Cash() >= withdrawal_sum;
}

double AtmInteractor::Cash() { return user_.Cash(); }
