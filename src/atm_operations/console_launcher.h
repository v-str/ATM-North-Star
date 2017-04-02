#ifndef CONSOLE_LAUNCHER_H
#define CONSOLE_LAUNCHER_H

#include "atm_user.h"
#include "demo_mode.h"
#include "initial_messenger.h"
#include "user_input.h"
#include "user_messenger.h"
#include "user_registrator.h"

#include "account_informator.h"
#include "refill.h"
#include "user_credit.h"
#include "user_statement.h"
#include "withdrawal.h"

class ConsoleLauncher {
 public:
  void RunInitialScreen();

 private:
  enum ProgramMenu { kDemo = 1, kRegistration };

  enum ATMOperation {
    kAccount = 1,
    kRefill,
    kCredit,
    kWidthdrawal,
    kStatement,
    kExitProgram,
  };

  enum ResultOfDecision { kMainMenu = 1, kExit };

  void RunInitialProgamMenu(int user_choice);
  void RunInitialMenuOperation(int user_choice);
  void RunDemoMode();
  void RegistrateUser();

  void RunMainProgramMenu();
  void ExecuteATMOperation(int user_choice);

  void RunAccountInfo();
  void RunRefill();
  void RunCredit();
  void RunWithdraw();
  void RunStatement();

  void GetExitResult();

  bool IsCorrectRegistration() const;

  void EndProgram() const;

  void ShowIncorrectRegistration() const;

  InitialMessenger initial_messenger_;
  UserInput user_input_;
  DemoMode demo_mode_;
  AtmUser atm_user_profile_;
  UserRegistrator registrator_;
  UserMessenger user_messenger_;

  AccountInformator account_informator_;
  Refill refill_;
  UserCredit user_credit_;
  Withdrawal withdrawal_;
  UserStatement statement_;

  bool user_want_to_exit_ = true;
};

#endif  // CONSOLE_LAUNCHER_H
