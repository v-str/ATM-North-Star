#ifndef CONSOLE_STATEMENT_MENU_H
#define CONSOLE_STATEMENT_MENU_H

class ConsoleStatementMenu {
 public:
  void RunStatement(int amount_of_cash);

  bool UserWantQuit() const;

 private:
  enum SubMenuItems { kMainMenu = 1, kQuit };

  void ProcessUserInput();
  bool IsUserInputCorrect(int user_input);
  void ResetManipulationFlags();

  bool user_want_main_menu_ = false;
  bool user_want_quit_ = false;
};

#endif  // CONSOLE_STATEMENT_MENU_H
