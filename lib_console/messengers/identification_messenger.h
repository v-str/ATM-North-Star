#ifndef IDENTIFICATION_MESSENGER_H
#define IDENTIFICATION_MESSENGER_H

class IdentificationMessenger {
 public:
  static void ShowInitialLoginText();
  static void ShowInitialPasswordText();

 private:
  static constexpr int kMaxLenghtOfLogin = 21;
  static constexpr int kMaxLenghtOfPassword = 4;
  static constexpr int kDelay = 50;
};

#endif  // IDENTIFICATION_MESSENGER_H
