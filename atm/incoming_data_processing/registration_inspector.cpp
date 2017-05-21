#include <registration_inspector.h>

#include <registration_standard.h>

ATM::LoginStatus RegistrationInspector::InspectLoginString(
    const std::string& login) {
  if (IsLoginShort(login)) {
    return ATM::LoginStatus::kShortLogin;
  } else if (IsLoginLong(login)) {
    return ATM::LoginStatus::kLongLogin;
  }

  if (IsStringContainSpecialSymbols(login)) {
    return ATM::LoginStatus::kSpecialSymbols;
  }

  return ATM::LoginStatus::kCorrectLogin;
}

bool RegistrationInspector::IsLoginShort(const std::string& login) const {
  return login.length() < RegistrationStandard::MinLoginLength();
}

bool RegistrationInspector::IsLoginLong(const std::string& login) const {
  return login.length() > RegistrationStandard::MaxLoginLength();
}

bool RegistrationInspector::IsStringContainSpecialSymbols(
    const std::string& string) {
  string_analyzer_.AnalyzeString(string);
  return string_analyzer_.IsStringContainSpecialSymbols();
}
