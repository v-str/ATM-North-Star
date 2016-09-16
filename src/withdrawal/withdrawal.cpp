#include "withdrawal.h"

int Withdrawal::SumOfWithdrawal() const {
  cout << "\n\t# Please, enter the required sum: ";

  int withdraw_sum = 0;
  cin >> withdraw_sum;

  return withdraw_sum;
}

bool Withdrawal::IsWithdrawalAcceptable(const CashOperator &cash_operator,
                                        double cash_sum) const {
  return cash_sum > 0 && cash_sum <= cash_operator.GetCash();
}

bool Withdrawal::IsCorrectPasswordAtWithdrawal(
    const Withdrawal::string &password, UserIdentifier &user_identifier) const {
  return password == user_identifier.GetPassword();
}

void Withdrawal::WithdrawFromAccount(CashOperator &cash_operator,
                                     int sum_of_withdrawal) {
  cash_operator.WithdrawCashFromUser(sum_of_withdrawal);
}
