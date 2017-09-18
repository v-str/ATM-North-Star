#ifndef STATEMENT_MANAGER_H
#define STATEMENT_MANAGER_H

class StatementManager {
 public:
  void RunStatement(int amount_of_cash);

 private:
  bool user_want_quit_ = false;
};

#endif  // STATEMENT_MANAGER_H
