#ifndef DEMO_USER_MESSANGER_H
#define DEMO_USER_MESSANGER_H

class DemoUserMessenger {
 public:
  enum MessageType {
    kWelcome,
    kAccountInfo,
    kRefillInfo,
    kCreditInfo,
    kWithdrawalInfo,
    kStatementInfo
  };

  enum DisplayMode { kCLearScreen, kNoClearScreen };

  static void ShowMessage(MessageType message_type);

  static void ShowDemoMenu(DisplayMode display_mode);

  static void ShowIncorrectInput();
  static void ShowIncorrectMenuInput();
  static void SuggestExit();

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
