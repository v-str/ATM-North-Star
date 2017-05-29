#ifndef CONSOLE_MODE_H
#define CONSOLE_MODE_H

#include <memory>

#include "atm_user.h"
#include "demo_mode.h"
#include "user_registrator.h"

#include "account_informator.h"
#include "refill.h"
#include "user_statement.h"
#include "withdrawal.h"

#include "cli_credit_department.h"

// ================ New Code ================

class Atm;
class UserInputProcessor;
class QuitMenuHandler;

class ConsoleMode {
 public:
  ConsoleMode();
  ~ConsoleMode();

  void RunATM();

 private:
  enum InitialProgramSection { kQuit, kDemo, kRegistration };
  enum ResultOfUserInput { kMainMenu = 1, kSubMenuQuit };
  enum AtmOperations {
    kAccount = 1,
    kRefill,
    kCredit,
    kWidthdrawal,
    kStatement,
    kExitProgram,
  };

  bool IsCorrectRegistration() const;
  void EndProgram() const;
  void ShowIncorrectRegistration() const;

  void RunProgram();
  void RunSectionBasedOn(int user_choice);
  void DemoMenu();
  void RegistrateUser();
  void MainProgramMenu();
  void ExecuteOperation(int user_choice);
  void SuggestToQuit();

  DemoMode demo_mode_;
  AtmUser user_;
  UserRegistrator registrator_;
  AccountInformator account_informator_;
  Refill refill_;
  Withdrawal withdrawal_;
  UserStatement statement_;
  CLICreditDepartment credit_department_;

  bool user_want_to_exit_ = true;

  // ============= New Code ==================
  std::unique_ptr<Atm> atm_;
  std::unique_ptr<UserInputProcessor> user_input_;
  std::unique_ptr<QuitMenuHandler> quit_menu_handler_;
};

#endif  // CONSOLE_MODE_H
