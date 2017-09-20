#ifndef DESCRIPTION_MESSENGER_H
#define DESCRIPTION_MESSENGER_H

class DescriptionMessenger {
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
  static void ShowReturnMessage();

 private:
  static const int kSleep = 100;

  static void ShowWelcomeDemoMessage();
  static void ShowDemoAccountInfoMessage();
  static void ShowInfoAboutRefillMessage();
  static void ShowDemoCreditAppMessage();
  static void ShowDemoWidthdrawalMessage();
  static void ShowDemoStatementMessage();
};

#endif  // DESCRIPTION_MESSENGER_H
