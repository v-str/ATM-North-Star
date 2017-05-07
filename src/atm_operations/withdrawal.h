#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <string>

#include <notice_messenger.h>
#include <user_input.h>

class AtmUser;

class Withdrawal {
 public:
  void WithdrawCashFrom(AtmUser* atm_user);

 private:
  static bool IsWithdrawalAcceptable(AtmUser* atm_user, double cash_sum);
  static bool IsCorrectPasswordAtWithdrawal(const std::string& password,
                                            AtmUser* atm_user);

  static void WithdrawFromAccount(AtmUser* atm_user, int sum_of_withdrawal);

  static constexpr int kNull = 0;

  int GetSumOfWithdrawal() const;

  UserInput user_input_;
  NoticeMessenger notice_messenger_;
};

#endif  // WITHDRAWAL_H
