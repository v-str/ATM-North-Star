#include "withdrawal.h"
#include "system_utility.h"

void Withdrawal::WithdrawCashFromUser(CashOperator &cash_operator,
                                      UserIdentifier &user_identifier) {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.ClearScreen();
  int sum_of_withdrawal = GetSumOfWithdrawal();
  if (IsWithdrawalAcceptable(cash_operator, sum_of_withdrawal)) {
    withdrawal_messenger_.ShowSumOfWithdrawal(sum_of_withdrawal);
    withdrawal_messenger_.ShowPasswordString();
    string password = user_input_.GetDataFromUser();
    if (IsCorrectPasswordAtWithdrawal(password, user_identifier)) {
      WithdrawFromAccount(cash_operator, sum_of_withdrawal);
      withdrawal_messenger_.ShowSuccessfulWithdrawal(sum_of_withdrawal,
                                                     cash_operator.GetCash());
    } else {
      withdrawal_messenger_.ShowIncorrectPasswordMessage();
    }
  } else {
    int amount_of_cash = cash_operator.GetCash();

    notice_messenger_.ShowUnacceptableWithdrawal(amount_of_cash);
  }
}

int Withdrawal::GetSumOfWithdrawal() const {
  withdrawal_messenger_.EnterSumOfWithdrawal();
  int withdraw_sum = user_input_.GetValueFromUser();
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
