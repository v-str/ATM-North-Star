#ifndef CONSOLE_WITHDRAWAL_MANAGER_H
#define CONSOLE_WITHDRAWAL_MANAGER_H

#include <string>

class ConsoleWithdrawalManager {
 public:
  void ShowWithdrawNotification();

  std::string GetPasswordFromUser() const;
  int SumOfWithdrawal() const;
  bool UserWantQuit() const;

 private:
  enum SubMenuItems { kNull, kMainMenu, kQuit };

  void ProcessUserInput();
  bool IsUserInputCorrect(int user_input);
  void ResetManipulationFlags();

  bool user_want_quit_ = false;
  int sum_of_withdrawal_ = 0;
};

#endif  // CONSOLE_WITHDRAWAL_MANAGER_H
