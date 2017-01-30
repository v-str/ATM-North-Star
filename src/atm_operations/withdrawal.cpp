#include "withdrawal.h"

void Withdrawal::WithdrawCashFromUser(AtmUser *atm_user) {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.ClearScreen();
  int sum_of_withdrawal = GetSumOfWithdrawal();
  if (IsWithdrawalAcceptable(atm_user, sum_of_withdrawal)) {
    withdrawal_messenger_.ShowSumOfWithdrawal(sum_of_withdrawal);
    withdrawal_messenger_.ShowPasswordString();
    string password = user_input_.GetDataFromUser();
    if (IsCorrectPasswordAtWithdrawal(password, atm_user)) {
      WithdrawFromAccount(atm_user, sum_of_withdrawal);
      withdrawal_messenger_.ShowSuccessfulWithdrawal(sum_of_withdrawal,
                                                     atm_user->get_cash());
    } else {
      withdrawal_messenger_.ShowIncorrectPasswordMessage();
    }
  } else {
    int amount_of_cash = atm_user->get_cash();

    notice_messenger_.ShowUnacceptableWithdrawal(amount_of_cash);
  }
}

int Withdrawal::GetSumOfWithdrawal() const {
  withdrawal_messenger_.EnterSumOfWithdrawal();
  int withdraw_sum = user_input_.GetValueFromUser();
  return withdraw_sum;
}

bool Withdrawal::IsWithdrawalAcceptable(AtmUser *atm_user, double cash_sum) {
  return cash_sum > 0 && cash_sum <= atm_user->get_cash();
}

bool Withdrawal::IsCorrectPasswordAtWithdrawal(
    const Withdrawal::string &password, AtmUser *atm_user) {
  return password == atm_user->get_password();
}

void Withdrawal::WithdrawFromAccount(AtmUser *atm_user, int sum_of_withdrawal) {
  atm_user->withdraw_cash(sum_of_withdrawal);
}
