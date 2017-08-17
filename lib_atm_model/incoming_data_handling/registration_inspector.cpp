#include <registration_inspector.h>

#include <registration_data_length_standard.h>

ATM::LogonStatus RegistrationInspector::InspectLoginString(const std::string& login) {
  string_analyzer_.AnalyzeString(login);

  if (IsLoginShort(login.length())) {
    return ATM::LogonStatus::kShortLogin;
  }
  if (IsLoginLong(login.length())) {
    return ATM::LogonStatus::kLongLogin;
  }
  if (IsStringContainSpecialSymbols()) {
    return ATM::LogonStatus::kSpecialSymbols;
  }
  if (IsStringBeginWithSpace()) {
    return ATM::LogonStatus::kBeginWithSpace;
  }
  if (IsStringEndWithSpace()) {
    return ATM::LogonStatus::kEndWithSpace;
  }
  if (IsStringContainAdjacentSpaces()) {
    return ATM::LogonStatus::kAdjacentSpaces;
  }
  if (IsStringContainOnlyDigits()) {
    return ATM::LogonStatus::kContainOnlyDigits;
  }
  if (IsStringEmpty()) {
    return ATM::LogonStatus::kEmptyString;
  }

  return ATM::LogonStatus::kCorrectLogin;
}

ATM::LogonStatus RegistrationInspector::InspectPasswordString(
    const std::string& password) {
  string_analyzer_.AnalyzeString(password);

  if (IsPasswordShort(password.length())) {
    return ATM::LogonStatus::kShortPassword;
  }
  if (IsPasswordLong(password.length())) {
    return ATM::LogonStatus::kLongPassword;
  }
  if (IsPasswordContainSpaces()) {
    return ATM::LogonStatus::kContainSpaceSymbol;
  }
  if (IsStringContainSpecialSymbols()) {
    return ATM::LogonStatus::kSpecialSymbols;
  }
  if (IsStringEmpty()) {
    return ATM::LogonStatus::kEmptyString;
  }

  return ATM::LogonStatus::kCorrectPassword;
}

bool RegistrationInspector::IsLoginShort(int login_length) const {
  return login_length < RegistrationDataLengthStandard::MinLoginLength();
}

bool RegistrationInspector::IsLoginLong(int login_length) const {
  return login_length > RegistrationDataLengthStandard::MaxLoginLength();
}

bool RegistrationInspector::IsPasswordShort(int password_length) const {
  return password_length < RegistrationDataLengthStandard::PasswordLength();
}

bool RegistrationInspector::IsPasswordLong(int password_length) const {
  return password_length > RegistrationDataLengthStandard::PasswordLength();
}

bool RegistrationInspector::IsPasswordContainSpaces() const {
  return string_analyzer_.AmountOfSpaces() > 0;
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

bool RegistrationInspector::IsStringContainAdjacentSpaces() const {
  return string_analyzer_.IsStringContainAdjacentSpaces();
}

bool RegistrationInspector::IsStringContainOnlyDigits() const {
  return string_analyzer_.IsStringContainOnlyDigits();
}

bool RegistrationInspector::IsStringEmpty() const {
  return string_analyzer_.IsStringEmpty();
}
