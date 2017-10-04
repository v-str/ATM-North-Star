#include <registration_data_length_standard.h>

int RegistrationDataLengthStandard::MinLoginLength() { return kMinLoginLength; }

int RegistrationDataLengthStandard::MaxLoginLength() { return kMaxLoginLength; }

int RegistrationDataLengthStandard::PasswordLength() { return kPasswordLength; }

int RegistrationDataLengthStandard::MaxPasswordTooltipLength() {
  return kMaxPasswordTooltipLength;
}
