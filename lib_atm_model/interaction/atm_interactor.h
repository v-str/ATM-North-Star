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

  static void RegisterUser(const std::string& login,
                           const std::string& password);
  static std::string AccountInfo(AtmInteractor::AccountData account_data);
  static void RefillCash(int refill_cash);
  static bool WithdrawCash(int withdrawal_cash);
  static std::string Statement();

 private:
  static bool IsWithdrawalAcceptable(int withdrawal_sum);

  static AtmUser user_;
};

#endif  // ATM_INTERACTOR_H
