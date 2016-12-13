#ifndef DEMO_USER_MESSANGER_H
#define DEMO_USER_MESSANGER_H

#include "console_editor.h"

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

  void ShowDemoMenuMessage() const;

  void ShowMessage(MessageType message_type);

 private:
  static const int kSleep = 100;

  void ShowDemoMenu() const;

  void ShowWelcomeDemoMessage() const;
  void ShowDemoAccountInfoMessage() const;
  void ShowInfoAboutRefillMessage() const;
  void ShowDemoCreditAppMessage() const;
  void ShowDemoWidthdrawalMessage() const;
  void ShowDemoStatementMessage() const;

  ConsoleEditor console_editor_;
};

#endif  // DEMO_USER_MESSANGER_H
