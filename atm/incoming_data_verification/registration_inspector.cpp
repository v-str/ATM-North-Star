#include <registration_inspector.h>

#include <registration_standard.h>

ATM::LoginStatus RegistrationInspector::InspectLoginString(
    const std::string& login) const {
  if (IsLoginShort(login)) {
    return ATM::LoginStatus::kShortLogin;
  } else if (IsLoginLong(login)) {
    return ATM::LoginStatus::kLongLogin;
  }

  // if (!IsDigits(login) || !IsAlphabeitSymbols(login)){
  // return ATM::LoginStatus::kInapropriateCharacters;
  // }

  return ATM::LoginStatus::kCorrectLogin;
}

bool RegistrationInspector::IsLoginShort(const std::string& login) const {
  return login.length() < RegistrationStandard::MinLoginLength();
}

bool RegistrationInspector::IsLoginLong(const std::string& login) const {
  return login.length() > RegistrationStandard::MaxLoginLength();
}
