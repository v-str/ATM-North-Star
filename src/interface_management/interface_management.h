#ifndef INTERFACE_MANAGER_H
#define INTERFACE_MANAGER_H

#include "user_input.h"

class InterfaceManager {
 public:
  void SuggestMode();

  int GetMode();

 private:
  void WriteWelcome();

  UserInput user_input_;

  int choice_ = 0;
};

#endif  // INTERFACE_MANAGER_H
