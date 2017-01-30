#ifndef PROGRAM_LAUNCHER_H
#define PROGRAM_LAUNCHER_H

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

class ProgramLauncher {
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

  void RunInitialProgamMenu(const size_t user_choice);
  void RunInitialMenuOperation(const size_t user_choice);
  void RunDemoMode();
  void RegistrateUser();

  void RunMainProgramMenu();
  void ExecuteATMOperation(size_t user_choice);

  void RunAccountInfo();
  void RunRefill();
  void RunCredit();
  void RunWithdraw();
  void RunStatement();

  void GetExitResult();

  bool IsCorrectRegistration();

  void EndProgram();

  void ShowIncorrectRegistration() const;

  InitialMessenger initial_messenger_;
  UserInput user_input_;
  DemoMode demo_mode_;
  UserRegistrator registrator_;
  AtmUser atm_user_profile_;
  UserMessenger user_messenger_;

  AccountInformator account_informator_;
  Refill refill_;
  UserCredit user_credit_;
  Withdrawal withdrawal_;
  UserStatement statement_;

  bool user_want_to_exit_ = true;
};

#endif  // PROGRAM_LAUNCHER_H
