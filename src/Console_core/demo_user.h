#ifndef DEMO_USER_H
#define DEMO_USER_H

#include "demo_user_messenger.h"
#include "notice_messenger.h"
#include "user_input.h"

#include <string>

class DemoUser {
  using string = std::string;

 public:
  void ShowDemoMode();
  bool UserWantToRegistrate() const;
  void UserWantToExitProgram();
  void UserDecideToExit();

 private:
  enum MenuSection {
    kAccountSection = 1,
    kRefillSection,
    kCreditSection,
    kWidthdrawalSection,
    kStatementSection,
    kExitSection,
    kRegistrationSection
  };

  void StartSection(DemoUserMessanger::MessageType message_type);
  void ForwardToRegistration();
  void StartRegistration();
  void SayGoodBye();

  bool user_want_to_exit_ = false;
  bool user_want_to_registrate_ = false;

  UserInput input_;
  DemoUserMessanger demo_messanger_;
  NoticeMessenger notice_messenger_;
};

#endif  // DEMO_USER_H
