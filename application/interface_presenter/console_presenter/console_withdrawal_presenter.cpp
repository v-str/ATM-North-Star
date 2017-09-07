#include <console_withdrawal_presenter.h>

#include <atm_interactor.h>
#include <cash_operation_validator.h>

void ConsoleWithdrawalPresenter::RunWithdrawalMenu() {
  user_want_quit_ = false;

  console_withdrawal_manager_.RunWithdrawalMenu();
  if (IsSumOfWithdrawalCorrect()) {
    if (IsPasswordCorrect()) {
      PerformWithdrawal();
    } else {
      // incorrect password message
    }
  } else if (console_withdrawal_manager_.UserWantQuit()) {
    user_want_quit_ = true;
  } else {
    // incorrect withdrawal message
  }
}

bool ConsoleWithdrawalPresenter::UserWantQuit() const {
  return user_want_quit_;
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

void ConsoleWithdrawalPresenter::PerformWithdrawal() const {
  AtmInteractor::WithdrawCash(console_withdrawal_manager_.SumOfWithdrawal());
  console_withdrawal_manager_.ShowSuccessfulWithdrawal();
}
