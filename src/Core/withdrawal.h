#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include "atm_user.h"
#include "console_editor.h"
#include "notice_messenger.h"
#include "user_input.h"
#include "withdrawal_messenger.h"

#include <string>

class Withdrawal {
  using string = std::string;

 public:
  void WithdrawCashFromUser(AtmUser &atm_user);

  int GetSumOfWithdrawal() const;
  static bool IsWithdrawalAcceptable(AtmUser &atm_user, double cash_sum);
  static bool IsCorrectPasswordAtWithdrawal(const string &password,
                                     AtmUser &atm_user);

  static void WithdrawFromAccount(AtmUser &atm_user, int sum_of_withdrawal);

 private:
  static const int kNull = 0;

  UserInput user_input_;
  WithdrawalMessenger withdrawal_messenger_;
  ConsoleEditor console_editor_;
  NoticeMessenger notice_messenger_;
};

#endif  // WITHDRAWAL_H
