#ifndef STATEMENT_MENU_H
#define STATEMENT_MENU_H

class StatementMenu {
 public:
  void RunStatement(int amount_of_cash);

  bool UserWantQuit() const;

 private:
  enum SubMenuItems { kMainMenu = 1, kQuit };

  void ProcessUserInput();
  void CheckUserInput(int user_input);
  void ResetManipulationFlags();

  bool user_want_main_menu_ = false;
  bool user_want_quit_ = false;
};

#endif  // STATEMENT_MENU_H
