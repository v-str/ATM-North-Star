#ifndef DEMO_USER_H
#define DEMO_USER_H

#include <string>

#include "demo_user_messenger.h"
#include "input/user_input.h"
#include "notice_messenger.h"

class DemoUser {
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
  NoticeMessenger notice_messenger_;
};

#endif  // DEMO_USER_H
