#ifndef DEMO_USER_H
#define DEMO_USER_H

#include <string>

#include "user_input.h"

class DemoUser {
  using string = std::string;

 public:
  void ShowDemoMode();
  bool UserWantToRegistrate() const;
  bool UserWantToExitProgram() const;

 private:
  bool UserDecideToExit();

  bool DemoAccountInfo() const;
  bool DemoRefill() const;
  bool DemoCreditApp() const;
  bool DemoWidthdrawal() const;
  bool DemoStatement() const;

  bool ShowIncorrectMessage() const;

  bool StartRegistration();

  void ShowDemoAccountInfo() const;

  void ShowInfoAboutRefill() const;

  bool user_want_to_registrate_ = false;
  UserInput user_input_;
};

#endif  // DEMO_USER_H
