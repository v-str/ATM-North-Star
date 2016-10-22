#ifndef INITIAL_SCREEN_H
#define INITIAL_SCREEN_H

#include "application.h"
#include "system_utility.h"

class InitialScreen {
 public:
  void DisplayInitialScreen();

 private:
  void DisplayInitialMenu() const;
  void DisplayError() const;

  void DisplayLogotype();
  void EatLine();

  SystemUtility utility_;
};

#endif  // INITIAL_SCREEN_H
