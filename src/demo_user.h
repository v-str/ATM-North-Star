#ifndef DEMO_USER_H
#define DEMO_USER_H

#include <string>

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
  bool StartRegistration();
  bool SuggestUserToExit() const;

  void DemoCreditAppconst() const;

  bool DemoWidthdrawal() const;

  bool DemoStatement() const;

  void ShowExitMessage() const;

  void Registration() const;

  void ClearScreen() const;

  bool ShowIncorrectMessage() const;

  void RunProgramUntilUserWantToExit() const;

  void SetupProgram() const;

  bool RunProgram() const;

  bool IsNormalLogin() const;

  bool IsNormalPass() const;

  bool DemoCreditApp() const;

  void ShowWelcomeMessage() const;

  int GetValueFromUser() const;

  void ShowDemoMenu() const;

  bool SuggestUserToExit(const string &menu_text, const string &choice_text);

  void ShowDemoAccountInfo() const;

  bool user_want_to_registrate = false;
  void ShowInfoAboutRefill() const;
};

#endif  // DEMO_USER_H
