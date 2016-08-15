#ifndef DEMO_USER_H
#define DEMO_USER_H

class DemoUser {
 public:
  void DemoMode() const;

 private:
  void DemoAccInfo() const;
  void DemoRefill() const;
  void DemoExit() const;
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
  void ShowDemoMenuText() const;

  int GetValueFromUser() const;
};

#endif  // DEMO_USER_H
