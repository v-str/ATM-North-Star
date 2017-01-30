#ifndef CONSOLE_APPLICATION_H
#define CONSOLE_APPLICATION_H

#include "account_informator.h"
#include "demo_user.h"
#include "initial_messenger.h"
#include "refill.h"
#include "user_credit.h"
#include "user_data/atm_user.h"
#include "user_messenger.h"
#include "user_registrator.h"
#include "user_statement.h"
#include "withdrawal.h"

class Application {
 public:
  enum ProgramMode { kConsoleMode = 1, kGraphicalMode };

  void RunProgram(std::size_t mode);

 private:
  enum UserDecision { kMainMenu = 1, kExit };

  enum ProgramAction {
    kDemonstration = 1,
    kRegistration,
  };

  enum Menu {
    kAccount = 1,
    kRefill,
    kCredit,
    kWidthdrawal,
    kStatement,
    kExitProgram,
  };

  int GetProgramSection();

  void RunSectionBasedOnChoice(int user_choice);

  void RegisterUser();
  void StartMainMenu();
  void DoProgramSection(int choice);
  void DisplayMainMenu();

  void ShowAccountInfo();
  void RefillOperation();
  void CreditApplication();
  void WithdrawCash();
  void Statement();

  void GetExitResult();

  bool user_want_to_exit_ = true;

  AtmUser atm_user_;
  Refill refill_;
  UserCredit user_credit_;
  Withdrawal withdrawal_;
  UserStatement statement_;
  UserMessenger user_messenger_;
  UserRegistrator registrator_;
  DemoUser demo_mode_;
  AccountInformator account_informator_;
  UserInput user_input_;
  InitialMessenger init_screen_;
};

#endif  // CONSOLE_APPLICATION_H