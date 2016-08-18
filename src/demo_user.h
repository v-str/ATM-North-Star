#ifndef DEMO_USER_H
#define DEMO_USER_H

#include <string>

class DemoUser {
  using string = std::string;

 public:
    void ShowDemoMode();

    bool RunDemoModeUntilUserWantToExit();
 private:

  bool DemoAccInfo() const;

  bool DemoRefill() const;

  bool SuggestUserToExit() const;

  void DemoCreditAppconst() const;

  void DemoWidthdrawal() const;

  void DemoStatement() const;

  void ShowExitMessage() const;

  void Registration() const;

  void ClearScreen() const;

  void ShowIncorrectDataMessage() const;

  void RunProgramUntilUserWantToExit() const;

  void SetupProgram() const;

  bool RunProgram() const;

  bool IsNormalLogin() const;

  bool IsNormalPass() const;

  void DemoCreditApp() const;

  void ShowWelcomeMessage() const;

  int GetValueFromUser() const;
  void ShowDemoMenu() const;
};

#endif  // DEMO_USER_H
