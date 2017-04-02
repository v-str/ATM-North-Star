#ifndef DEMO_MODE_H
#define DEMO_MODE_H

#include <string>

#include "demo_user_messenger.h"
#include "user_input.h"

class DemoMode {
  using string = std::string;

 public:
  void ShowDemoMode();
  bool UserWantToRegistrate() const;
  void UserWantToExitProgram();
  void GetUserDecision();

 private:
  enum UserDecision { kMainMenu = 1, kExit };

  enum MenuSection {
    kAccountSection = 1,
    kRefillSection,
    kCreditSection,
    kWidthdrawalSection,
    kStatementSection,
    kExitSection,
    kRegistrationSection
  };

  void StartSection(DemoMessanger::MessageType message_type);
  void ForwardToRegistration();
  void StartRegistration();
  void GetExitResult();
  void SayGoodBye();

  bool user_want_to_exit_ = true;
  bool user_want_to_registrate_ = false;

  UserInput user_input_;
  DemoMessanger demo_messenger_;
};

#endif  // DEMO_MODE_H
