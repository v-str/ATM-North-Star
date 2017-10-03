#ifndef ATM_INTERACTOR_H
#define ATM_INTERACTOR_H

#include <string>
#include <vector>

#include <atm_user.h>

class AtmInteractor {
 public:
  static void PerformUserRegistration(const std::string& login,
                                      const std::string& password);
  static std::vector<std::string> AccountInfo();
  static void RefillCash(int refill_cash);
  static void WithdrawCash(int withdrawal_cash);

  static bool IsPasswordCorrect(const std::string& password_string);
  static bool IsWithdrawalAcceptable(int withdrawal_sum);

  static double Cash();

  static void ResetData();

 private:
  static AtmUser user_;
};

#endif  // ATM_INTERACTOR_H
