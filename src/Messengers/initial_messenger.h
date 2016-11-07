#ifndef INITIAL_MESSENGER_H
#define INITIAL_MESSENGER_H

#include "system_utility.h"

class InitialMessenger {
 public:
  void DisplayInitialScreen();

 private:
  void DisplayInitialMenu() const;
  void DisplayError() const;

  void DisplayLogotype();
  void EatLine();

  SystemUtility utility_;
};

#endif  // INITIAL_MESSENGER_H
