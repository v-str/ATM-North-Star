#include <console_withdrawal_presenter.h>

#include <atm_interactor.h>
#include <cash_operation_validator.h>

void ConsoleWithdrawalPresenter::RunWithdrawalMenu() {
  console_withdrawal_manager_.RunWithdrawalMenu();
  if (IsSumOfWithdrawalCorrect()) {
    if (IsPasswordCorrect()) {
      AtmInteractor::WithdrawCash(
          console_withdrawal_manager_.SumOfWithdrawal());
    }
  }
}

bool ConsoleWithdrawalPresenter::UserWantQuit() const {
  return console_withdrawal_manager_.UserWantQuit();
}

bool ConsoleWithdrawalPresenter::IsSumOfWithdrawalCorrect() const {
  bool correct_withdrawal_sum =
      CashOperationValidator::IsWithdrawalCorrect(
          console_withdrawal_manager_.SumOfWithdrawal()) &&
      AtmInteractor::IsWithdrawalAcceptable(
          console_withdrawal_manager_.SumOfWithdrawal());

  return correct_withdrawal_sum;
}

bool ConsoleWithdrawalPresenter::IsPasswordCorrect() const {
  bool is_password_correct = AtmInteractor::IsPasswordCorrect(
      console_withdrawal_manager_.GetPasswordFromUser());

  return is_password_correct;
}
