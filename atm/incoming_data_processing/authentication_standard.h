#ifndef AUTHENTIFICATION_STANDARD_H
#define AUTHENTIFICATION_STANDARD_H

class AuthenticationStandard {
 public:
  static int MinLoginLength();
  static int MaxLoginLength();
  static int PasswordLength();

 private:
  static constexpr int k_min_login_length_ = 4;
  static constexpr int k_max_login_length_ = 35;
  static constexpr int k_password_length_ = 6;
};

#endif  // AUTHENTIFICATION_STANDARD_H
