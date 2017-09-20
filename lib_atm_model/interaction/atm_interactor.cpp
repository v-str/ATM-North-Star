#include <atm_interactor.h>

#include <account_informator.h>
#include <refill.h>
#include <user_registrator.h>
#include <withdrawal.h>

AtmUser AtmInteractor::user_;

void AtmInteractor::PerformUserRegistration(const std::string& login,
                                            const std::string& password) {
  ResetData();

  UserRegistrator::RegisterUser(&user_, login, password);
}

std::vector<std::string> AtmInteractor::AccountInfo() {
  AccountInformator::UpdataUserData(user_);

  std::vector<std::string> account_info;

  account_info.push_back(AccountInformator::Login());
  account_info.push_back(AccountInformator::Cash());
  account_info.push_back(AccountInformator::CreditSum());
  account_info.push_back(AccountInformator::CreditTerm());
  account_info.push_back(AccountInformator::InterestRate());
  account_info.push_back(AccountInformator::MonthlyPayment());

  return account_info;
}

void AtmInteractor::RefillCash(int refill_cash) {
  Refill::RefillCash(&user_, refill_cash);
}

void AtmInteractor::WithdrawCash(int withdrawal_cash) {
  Withdrawal::WithdrawCashFrom(&user_, withdrawal_cash);
}

std::string AtmInteractor::Statement() {
  AccountInformator::UpdataUserData(user_);
  return AccountInformator::Cash();
}

void AtmInteractor::ResetData() { user_.ResetData(); }

bool AtmInteractor::IsPasswordCorrect(const std::string& password_string) {
  return password_string == user_.Password();
}

bool AtmInteractor::IsWithdrawalAcceptable(int withdrawal_sum) {
  return user_.Cash() >= withdrawal_sum;
}

double AtmInteractor::Cash() { return user_.Cash(); }
