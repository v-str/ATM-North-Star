#include <withdrawal.h>

#include <atm_user.h>
#include <console_editor.h>
#include <withdrawal_messenger.h>

void Withdrawal::WithdrawCashFrom(AtmUser* atm_user) {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::ClearScreen();
  int sum_of_withdrawal = GetSumOfWithdrawal();
  if (IsWithdrawalAcceptable(atm_user, sum_of_withdrawal)) {
    WithdrawalMessenger::ShowSumOfWithdrawal(sum_of_withdrawal);
    WithdrawalMessenger::ShowPasswordString();
    std::string password = user_input_.GetDataFromUser();
    if (IsCorrectPasswordAtWithdrawal(password, atm_user)) {
      WithdrawFromAccount(atm_user, sum_of_withdrawal);
      WithdrawalMessenger::ShowSuccessfulWithdrawal(sum_of_withdrawal,
                                                    atm_user->Cash());
    } else {
      WithdrawalMessenger::ShowIncorrectPasswordMessage();
    }
  } else {
    int amount_of_cash = atm_user->Cash();

    notice_messenger_.ShowUnacceptableWithdrawal(amount_of_cash);
  }
}

int Withdrawal::GetSumOfWithdrawal() const {
  WithdrawalMessenger::EnterSumOfWithdrawal();
  int withdraw_sum = user_input_.GetValueFromUser();
  return withdraw_sum;
}

bool Withdrawal::IsWithdrawalAcceptable(AtmUser* atm_user, double cash_sum) {
  return cash_sum > 0 && cash_sum <= atm_user->Cash();
}

bool Withdrawal::IsCorrectPasswordAtWithdrawal(const std::string& password,
                                               AtmUser* atm_user) {
  return password == atm_user->Password();
}

void Withdrawal::WithdrawFromAccount(AtmUser* atm_user, int sum_of_withdrawal) {
  atm_user->WithdrawCash(sum_of_withdrawal);
}
