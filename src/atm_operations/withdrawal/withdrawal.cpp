#include "withdrawal.h"

const int kint_null = 0;

bool Withdrawal::WithdrawCashFromUser(CashOperator &cash_operator,
                                      UserIdentifier &user_identifier) {
  int sum_of_withdrawal = SumOfWithdrawal();
  if (IsWithdrawalAcceptable(cash_operator, sum_of_withdrawal)) {
    messenger_.ShowSumOfWithdrawal(sum_of_withdrawal);
    messenger_.ShowPasswordString();
    string password = user_identifier.GetPasswordFromUser();
    if (IsCorrectPasswordAtWithdrawal(password, user_identifier)) {
      WithdrawFromAccount(cash_operator, sum_of_withdrawal);
      messenger_.ShowSuccessfulWithdrawal(sum_of_withdrawal,
                                          cash_operator.GetCash());
    } else {
      messenger_.ShowIncorrectPasswordMessage();
    }
  } else {
    int amount_of_cash = cash_operator.GetCash();
    error_message_.NoticeUnacceptableWithdrawal(amount_of_cash,
                                                sum_of_withdrawal);
  }
  return user_input_.SuggestUserToExit();
}

int Withdrawal::SumOfWithdrawal() const {
  messenger_.ShowSentenceEnterASumOfMoney();
  int withdraw_sum = kint_null;
  cin >> withdraw_sum;
  return withdraw_sum;
}

bool Withdrawal::IsWithdrawalAcceptable(const CashOperator &cash_operator,
                                        double cash_sum) const {
  return cash_sum > kint_null && cash_sum <= cash_operator.GetCash();
}

bool Withdrawal::IsCorrectPasswordAtWithdrawal(
    const Withdrawal::string &password, UserIdentifier &user_identifier) const {
  return password == user_identifier.GetPassword();
}

void Withdrawal::WithdrawFromAccount(CashOperator &cash_operator,
                                     int sum_of_withdrawal) {
  cash_operator.WithdrawCashFromUser(sum_of_withdrawal);
}
