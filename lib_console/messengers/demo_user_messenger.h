#ifndef DEMO_USER_MESSANGER_H
#define DEMO_USER_MESSANGER_H

#include "console_editor.h"

class DemoMessanger {
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

  void ShowDemoMenuAgain() const;
  void ShowMessage(MessageType message_type) const;
  void ShowIncorrectInput() const;
  void ShowIncorrectMenuInput() const;
  void SuggestExit() const;
  void ShowDemoMenu() const;

 private:
  static const int kSleep = 100;

  void ShowWelcomeDemoMessage() const;
  void ShowDemoAccountInfoMessage() const;
  void ShowInfoAboutRefillMessage() const;
  void ShowDemoCreditAppMessage() const;
  void ShowDemoWidthdrawalMessage() const;
  void ShowDemoStatementMessage() const;

  ConsoleEditor console_editor_;
};

#endif  // DEMO_USER_MESSANGER_H
