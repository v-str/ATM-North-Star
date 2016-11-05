#ifndef DEMO_USER_MESSANGER_H
#define DEMO_USER_MESSANGER_H

#include "user_input.h"

class DemoUserMessanger {
 public:
  enum MessageType {
    kWelcome,
    kMenu,
    kAccountInfo,
    kRefill,
    kCreditApp,
    kWithdrawal,
    kStatement
  };

  void ShowWelcomeDemoMessage() const;
  void ShowDemoAccountInfoMessage() const;
  void ShowInfoAboutRefillMessage() const;
  void ShowDemoCreditAppMessage() const;
  void ShowDemoWidthdrawalMessage() const;
  void ShowDemoStatementMessage() const;
  void ShowDemoMenuMessage() const;

  void ShowMessage(MessageType message_type);

 private:
  static const int kSleep = 100;

  void ShowDemoMenu() const;

  SystemUtility utility_;
};

#endif  // DEMO_USER_MESSANGER_H
