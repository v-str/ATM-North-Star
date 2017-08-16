#ifndef LOGON_MESSENGER_H
#define LOGON_MESSENGER_H

class LogonMessenger {
 public:
  enum StringLength {
    kShortLoginLength,
    kLongLoginLength,
    kShortPasswordLength,
    kLongPasswordLength
  };
  enum ContainSpaceSymbol { kBeginWithSpace, kEndWithSpace, kAdjecentSpaces };

  static void CorrectLoginMessage();
  static void LoginLengthStatus(StringLength login_length);
  static void LoginContainSpecialSymbol();
  static void LoginContainIncorrectSpacePosition(
      ContainSpaceSymbol space_symbol);
  static void LoginContainOnlyDigits();
  static void LoginEmpty();

  static void CorrectPasswordMessage();
  static void PasswordLength(StringLength password_length);
  static void PasswordContainSpaceSymbol();
  static void PasswordEmpty();

  static void AddEmptyLines(int amount_of_lines);

 private:
  static void WriteLoginTitleStatus();
  static void WritePasswordTitleStatus();

  static void WtiteDevidingLine();

  static constexpr int kMaxLenghtOfLogin = 21;
  static constexpr int kMaxLenghtOfPassword = 4;
  static constexpr int kDelay = 50;
};

#endif  // LOGON_MESSENGER_H
