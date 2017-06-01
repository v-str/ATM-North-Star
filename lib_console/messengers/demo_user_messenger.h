#ifndef DEMO_USER_MESSANGER_H
#define DEMO_USER_MESSANGER_H

class DemoUserMessenger {
 public:
  enum MessageType {
    kWelcome,
    kMenu,
    kAccountInfo,
    kRefillInfo,
    kCreditInfo,
    kWithdrawalInfo,
    kStatementInfo
  };

  static void ShowDemoMenuAgain();
  static void ShowMessage(MessageType message_type);
  static void ShowIncorrectInput();
  static void ShowIncorrectMenuInput();
  static void SuggestExit();
  static void ShowDemoMenu();

 private:
  static constexpr int kSleep = 100;

  static void ShowWelcomeDemoMessage();
  static void ShowDemoAccountInfoMessage();
  static void ShowInfoAboutRefillMessage();
  static void ShowDemoCreditAppMessage();
  static void ShowDemoWidthdrawalMessage();
  static void ShowDemoStatementMessage();
};

#endif  // DEMO_USER_MESSANGER_H
