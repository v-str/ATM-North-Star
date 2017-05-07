#ifndef DEMO_USER_MESSANGER_H
#define DEMO_USER_MESSANGER_H

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
  static constexpr int kSleep = 100;

  void ShowWelcomeDemoMessage() const;
  void ShowDemoAccountInfoMessage() const;
  void ShowInfoAboutRefillMessage() const;
  void ShowDemoCreditAppMessage() const;
  void ShowDemoWidthdrawalMessage() const;
  void ShowDemoStatementMessage() const;
};

#endif  // DEMO_USER_MESSANGER_H
