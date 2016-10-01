#ifndef INITIAL_SCREEN_H
#define INITIAL_SCREEN_H

#include "application.h"
#include "system_utility.h"

class InitialScreen {
 public:
  void DisplayInitialScreen();

 private:
  void DisplayInitialMenu() const;
  void DisplayLogotype() const;
  void DisplayError() const;

  SystemUtility utility_;
  Application app_;
};

#endif  // INITIAL_SCREEN_H
