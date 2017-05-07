#ifndef ATM_h
#define ATM_h

#include <string>

#include <atm_user.h>

class Atm {
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
  std::string AccountInfo(Atm::AccountData account_data);
  std::string Statement();
  bool WithdrawCash(int withdrawal_cash);
  void RefillCash(int refill_cash);

 private:
  bool IsWithdrawalAcceptable(int withdrawal_sum) const;

  AtmUser user_;
};

#endif  // ATM_h
