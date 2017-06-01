#ifndef AUTHENTICATION_MESSENGER_H
#define AUTHENTICATION_MESSENGER_H

class AuthenticationMessenger {
 public:
  enum StringLength { kShortLoginLength, kLongLoginLength };

  static void DisplayLoginText();
  static void DisplayPasswordText();

  static void LoginLength(StringLength string_length);
  static void LoginContainSpecialSymbol();
  static void LoginBeginWithSpace();

 private:
  static void WriteLoginTitleStatus();

  static constexpr int kMaxLenghtOfLogin = 21;
  static constexpr int kMaxLenghtOfPassword = 4;
  static constexpr int kDelay = 50;
};

#endif  // AUTHENTICATION_MESSENGER_H
