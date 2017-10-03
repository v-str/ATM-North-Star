#ifndef REGISTRATION_DATA_LENGTH_STANDARD_H
#define REGISTRATION_DATA_LENGTH_STANDARD_H

class RegistrationDataLengthStandard {
 public:
  static int MinLoginLength();
  static int MaxLoginLength();
  static int PasswordLength();

 private:
  static constexpr int kMinLoginLength_ = 6;
  static constexpr int kMaxLoginLength_ = 35;
  static constexpr int kPasswordLength_ = 6;
};

#endif  // REGISTRATION_DATA_LENGTH_STANDARD_H
