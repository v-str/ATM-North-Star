#ifndef CONSOLE_WITHDRAWAL_PRESENTER_H
#define CONSOLE_WITHDRAWAL_PRESENTER_H

#include <console_withdrawal_manager.h>

class ConsoleWithdrawalPresenter {
 public:
  void RunWithdrawalMenu();

  bool UserWantQuit() const;

 private:
  bool IsSumSuitable() const;
  bool IsPasswordCorrect() const;
  void PerformWithdrawal() const;

  ConsoleWithdrawalManager console_withdrawal_manager_;

  bool user_want_quit_ = false;
};

#endif  // CONSOLE_WITHDRAWAL_PRESENTER_H
