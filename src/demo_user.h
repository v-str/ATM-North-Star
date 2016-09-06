#ifndef DEMO_USER_H
#define DEMO_USER_H

#include <string>

#include "demo_user_messanger.h"
#include "user_input.h"

class DemoUser {
  using string = std::string;

  enum MenuSection {
    kAccountSection = 1,
    kRefillSection,
    kCreditSection,
    kWidthdrawalSection,
    kStatementSection,
    kExitSection,
    kRegistrationSection
  };

 public:
  void ShowDemoMode();
  bool UserWantToRegistrate();
  void UserWantToExitProgram();
  void UserDecideToExit();

 private:
  void StartRegistration();
  void SayGoodBye();
  void ForwardToRegistration();
  void StartSection(DemoUserMessanger::MessageType message_type);

  bool user_want_to_exit_ = false;
  bool user_want_to_registrate_ = false;
  UserInput user_input_;
  DemoUserMessanger demo_messanger_;
};

#endif  // DEMO_USER_H
