#ifndef ATM_INTERACTOR_H
#define ATM_INTERACTOR_H

#include <string>

class AtmUser;

class AtmInteractor {
 public:
  ~AtmInteractor();

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

  static void ResetData();

 private:
  static bool IsWithdrawalAcceptable(int withdrawal_sum);
  static void CheckOnUserExisting();

  static AtmUser* user_;
};

#endif  // ATM_INTERACTOR_H
