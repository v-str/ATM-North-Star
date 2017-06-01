#ifndef AUTHENTICATION_MESSENGER_H
#define AUTHENTICATION_MESSENGER_H

class AuthenticationMessenger {
 public:
  static void DisplayLoginText();
  static void DisplayPasswordText();

 private:
  static constexpr int kMaxLenghtOfLogin = 21;
  static constexpr int kMaxLenghtOfPassword = 4;
  static constexpr int kDelay = 50;
};

#endif  // AUTHENTICATION_MESSENGER_H
