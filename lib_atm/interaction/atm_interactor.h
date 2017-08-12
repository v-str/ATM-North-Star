#ifndef ATM_INTERACTOR_H
#define ATM_INTERACTOR_H

#include <string>

#include <atm_user.h>

class AtmInteractor {
 public:
  enum AccountData {
    kLogin,
    kCash,
    kCreditSum,
    kCreditTerm,
    kInterestRate,
    kMonthlyPayment
  };

  void RegisterUser(const std::string& login, const std::string& password);
  std::string AccountInfo(AtmInteractor::AccountData account_data);
  void RefillCash(int refill_cash);
  bool WithdrawCash(int withdrawal_cash);
  std::string Statement();

 private:
  bool IsWithdrawalAcceptable(int withdrawal_sum) const;

  AtmUser user_;
};

#endif  // ATM_INTERACTOR_H
