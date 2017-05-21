#include <registration_inspector.h>

#include <registration_standard.h>

ATM::LoginStatus RegistrationInspector::InspectLoginString(
    const std::string& login) {
  string_analyzer_.AnalyzeString(login);

  if (IsLoginShort(login)) {
    return ATM::LoginStatus::kShortLogin;
  } else if (IsLoginLong(login)) {
    return ATM::LoginStatus::kLongLogin;
  }

  if (IsStringContainSpecialSymbols()) {
    return ATM::LoginStatus::kSpecialSymbols;
  } else if (IsStringBeginWithSpace()) {
    return ATM::LoginStatus::kBeginWithSpace;
  } else if (IsStringEndWithSpace()) {
    return ATM::LoginStatus::kEndWithSpace;
  }

  // if(IsStringContainAdjacentSpaces(){
  // return ATM::LoginStatus::kAdjacentSpaces;
  // }

  return ATM::LoginStatus::kCorrectLogin;
}

bool RegistrationInspector::IsLoginShort(const std::string& login) const {
  return login.length() < RegistrationStandard::MinLoginLength();
}

bool RegistrationInspector::IsLoginLong(const std::string& login) const {
  return login.length() > RegistrationStandard::MaxLoginLength();
}

bool RegistrationInspector::IsStringContainSpecialSymbols() const {
  return string_analyzer_.IsStringContainSpecialSymbols();
}

bool RegistrationInspector::IsStringBeginWithSpace() const {
  return string_analyzer_.IsStringBeginWithSpace();
}

bool RegistrationInspector::IsStringEndWithSpace() const {
  return string_analyzer_.IsStringEndWithSpace();
}
