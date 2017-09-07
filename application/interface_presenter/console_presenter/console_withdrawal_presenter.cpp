#include <console_withdrawal_presenter.h>

#include <atm_interactor.h>
#include <cash_operation_validator.h>

void ConsoleWithdrawalPresenter::RunWithdrawalMenu() {
  user_want_quit_ = false;

  console_withdrawal_manager_.RunWithdrawalMenu();

  if (console_withdrawal_manager_.UserWantQuit()) {
    user_want_quit_ = true;
  } else {
    ProduceWithdrawalOperation();
  }
}

bool ConsoleWithdrawalPresenter::UserWantQuit() const {
  return user_want_quit_;
}

bool ConsoleWithdrawalPresenter::IsSumSuitable() const {
  bool is_withdrawal_correct = CashOperationValidator::IsWithdrawalCorrect(
      console_withdrawal_manager_.SumOfWithdrawal());

  bool is_withdrawal_acceptable = AtmInteractor::IsWithdrawalAcceptable(
      console_withdrawal_manager_.SumOfWithdrawal());

  return is_withdrawal_correct && is_withdrawal_acceptable;
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

void ConsoleWithdrawalPresenter::ProduceWithdrawalOperation() const {
  bool is_sum_suitable = IsSumSuitable();
  bool is_password_correct = IsPasswordCorrect();

  if (is_sum_suitable && is_password_correct) {
    PerformWithdrawal();
  } else {
    console_withdrawal_manager_.ShowIncorrectWithdrawal();
  }
}
