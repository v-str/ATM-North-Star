#ifndef REGISTRATION_STANDARD_H
#define REGISTRATION_STANDARD_H

class RegistrationStandard {
 public:
  static int MinLoginLength();

 private:
  static constexpr int k_min_login_length_ = 4;
};

#endif  // REGISTRATION_STANDARD_H
