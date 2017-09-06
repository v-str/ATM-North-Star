#ifndef CONSOLE_WITHDRAWAL_PRESENTER_H
#define CONSOLE_WITHDRAWAL_PRESENTER_H

#include <console_withdrawal_manager.h>

class ConsoleWithdrawalPresenter {
 public:
  void RunWithdrawalMenu();

 private:
  ConsoleWithdrawalManager console_withdrawal_manager_;
};

#endif  // CONSOLE_WITHDRAWAL_PRESENTER_H
