#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <iostream>
#include <string>

#include "cash_operator.h"
#include "notice_about_error.h"
#include "user_identifier.h"
#include "user_input.h"
#include "withdrawal_messenger.h"

using std::cout;
using std::cin;

class Withdrawal {
  using string = std::string;

 public:
  bool WithdrawCashFromUser(CashOperator &cash_operator,
                            UserIdentifier &user_identifier);

  int SumOfWithdrawal() const;
  bool IsWithdrawalAcceptable(const CashOperator &cash_operator,
                              double cash_sum) const;
  bool IsCorrectPasswordAtWithdrawal(const string &password,
                                     UserIdentifier &user_identifier) const;

  void WithdrawFromAccount(CashOperator &cash_operator, int sum_of_withdrawal);

 private:
  UserInput user_input_;
  NoticeAboutError error_message_;
  WithdrawalMessenger messenger_;
};

#endif  // WITHDRAWAL_H
