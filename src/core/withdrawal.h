#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <string>

#include "input/user_input.h"
#include "messengers/notice_messenger.h"
#include "messengers/withdrawal_messenger.h"
#include "output_configuration/console_editor.h"
#include "user_data/atm_user.h"

class Withdrawal {
  using string = std::string;

 public:
  void WithdrawCashFromUser(AtmUser *atm_user);

 private:
  static bool IsWithdrawalAcceptable(AtmUser *atm_user, double cash_sum);
  static bool IsCorrectPasswordAtWithdrawal(const string &password,
                                            AtmUser *atm_user);

  static void WithdrawFromAccount(AtmUser *atm_user, int sum_of_withdrawal);
  static const int kNull = 0;

  int GetSumOfWithdrawal() const;

  UserInput user_input_;
  WithdrawalMessenger withdrawal_messenger_;
  ConsoleEditor console_editor_;
  NoticeMessenger notice_messenger_;
};

#endif  // WITHDRAWAL_H
