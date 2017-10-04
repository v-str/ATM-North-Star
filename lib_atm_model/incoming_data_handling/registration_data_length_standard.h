#ifndef REGISTRATION_DATA_LENGTH_STANDARD_H
#define REGISTRATION_DATA_LENGTH_STANDARD_H

class RegistrationDataLengthStandard {
 public:
  static int MinLoginLength();
  static int MaxLoginLength();
  static int PasswordLength();
  static int MaxPasswordTooltipLength();

 private:
  static const int kMinLoginLength = 6;
  static const int kMaxLoginLength = 35;
  static const int kPasswordLength = 6;
  static const int kMaxPasswordTooltipLength = 50;
};

#endif  // REGISTRATION_DATA_LENGTH_STANDARD_H
