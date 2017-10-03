#include <registration_data_length_standard.h>

int RegistrationDataLengthStandard::MinLoginLength() {
  return kMinLoginLength_;
}

int RegistrationDataLengthStandard::MaxLoginLength() {
  return kMaxLoginLength_;
}

int RegistrationDataLengthStandard::PasswordLength() {
  return kPasswordLength_;
}
