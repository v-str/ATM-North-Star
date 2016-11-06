#include "withdrawal.h"

void Withdrawal::WithdrawCashFromUser(CashOperator &cash_operator,
                                      UserIdentifier &user_identifier) {
  utility_.ClearScreen();
  int sum_of_withdrawal = GetSumOfWithdrawal();
  if (IsWithdrawalAcceptable(cash_operator, sum_of_withdrawal)) {
    messenger_.ShowSumOfWithdrawal(sum_of_withdrawal);
    messenger_.ShowPasswordString();
    string password;
    std::cin >> password;
    if (IsCorrectPasswordAtWithdrawal(password, user_identifier)) {
      WithdrawFromAccount(cash_operator, sum_of_withdrawal);
      messenger_.ShowSuccessfulWithdrawal(sum_of_withdrawal,
                                          cash_operator.GetCash());
      utility_.IgnoreCinLine();
    } else {
      messenger_.ShowIncorrectPasswordMessage();
    }
  } else {
    int amount_of_cash = cash_operator.GetCash();

    notice_messenger_.ShowUnacceptableWithdrawal(amount_of_cash,
                                                 sum_of_withdrawal);
  }
}

int Withdrawal::GetSumOfWithdrawal() const {
  messenger_.EnterSumOfWithdrawal();
  int withdraw_sum = 0;
  std::cin >> withdraw_sum;
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
