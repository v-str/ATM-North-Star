#ifndef REGISTRATION_STATUS_MESSENGER_H
#define REGISTRATION_STATUS_MESSENGER_H

class RegistrationStatusMessenger {
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

  static void CorrectPasswordTooltip();
  static void IncorrectPasswordTooltip();

  static void AddEmptyLines(int amount_of_lines);

 private:
  static void WriteLoginTitleStatus();
  static void WritePasswordTitleStatus();
  static void WritePasswordTooltipStatus();

  static void WtiteDevidingLine();

  static const int kMaxLenghtOfLogin = 21;
  static const int kMaxLenghtOfPassword = 4;
  static const int kDelay = 50;
};

#endif  // REGISTRATION_STATUS_MESSENGER_H
