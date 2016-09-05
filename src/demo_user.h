#ifndef DEMO_USER_H
#define DEMO_USER_H

#include <string>

#include "demo_user_messanger.h"
#include "user_input.h"

class DemoUser {
  using string = std::string;

 public:
  void ShowDemoMode();

  bool UserWantToRegistrate();

  void UserWantToExitProgram();
  void UserDecideToExit();


private:
  void DemoAccountInfo();
  void DemoRefill();
  void DemoCreditApp();
  void DemoWidthdrawal();
  void DemoStatement();

  void StartRegistration();

  void StartAccountInfoSectionWithQuestionAboutExit();
  void StartRefillSectionWithQuestionAboutExit();
  void StartCreditSectionWithQuestionAboutExit();
  void StartWidthdrawalInfoSectionWithQuestionAboutExit();
  void StartStatementInfoSectionWithQuestionAboutExit();
  void SayGoodBye();
  void ForwardToRegistration();

  bool user_want_to_exit_ = false;
  bool user_want_to_registrate_ = false;
  UserInput user_input_;
  DemoUserMessanger demo_messanger_;
};

#endif  // DEMO_USER_H
