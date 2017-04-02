﻿#ifndef CONSOLE_LAUNCHER_H
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

  void InitialProgamMenu(int user_choice);
  void InitialMenuOperation(int user_choice);
  void DemoMenu();
  void RegistrateUser();

  void MainProgramMenu();
  void ATMOperation(int user_choice);

  void AccountInfoMenu();
  void RefillMenu();
  void CreditMenu();
  void WithdrawMenu();
  void StatementMenu();

  void SuggestToExit();

  bool IsCorrectRegistration() const;

  void EndProgram() const;

  void ShowIncorrectRegistration() const;

  InitialMessenger initial_messenger_;

  DemoMode demo_mode_;

  AtmUser user_;
  UserMessenger user_messenger_;

  UserRegistrator registrator_;

  AccountInformator account_informator_;
  Refill refill_;
  UserCredit user_credit_;
  Withdrawal withdrawal_;
  UserStatement statement_;

  UserInput user_input_;

  bool user_want_to_exit_ = true;
};

#endif  // CONSOLE_LAUNCHER_H
