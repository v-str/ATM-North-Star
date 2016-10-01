#ifndef INITIAL_SCREEN_H
#define INITIAL_SCREEN_H

#include "system_utility.h"

class InitialScreen {
 public:
  void InitialMenuBox() const;
  void Logotype() const;
  void Error() const;

 private:
  SystemUtility utility_;
};

#endif  // INITIAL_SCREEN_H
