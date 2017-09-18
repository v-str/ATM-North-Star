#ifndef CONSOLE_WITHDRAWAL_PRESENTER_H
#define CONSOLE_WITHDRAWAL_PRESENTER_H

#include <console_withdrawal_menu.h>

class ConsoleWithdrawalPresenter {
 public:
  void RunWithdrawalMenu();

  bool UserWantQuit() const;

 private:
  bool IsSumSuitable() const;
  bool IsPasswordCorrect() const;
  void PerformWithdrawal() const;
  void ProduceWithdrawalOperation() const;

  ConsoleWithdrawalMenu console_withdrawal_menu_;

  bool user_want_main_menu_ = false;
  bool user_want_quit_ = false;
};

#endif  // CONSOLE_WITHDRAWAL_PRESENTER_H
