#ifndef CONSOLE_CASH_REFILL_MANAGER_H
#define CONSOLE_CASH_REFILL_MANAGER_H

#include <user_input_handler.h>

class ConsoleCashRefillManager {
 public:
  void RunRefillMenu();

 private:
  UserInputHandler user_input_handler_;
};

#endif  // CONSOLE_CASH_REFILL_MANAGER_H
