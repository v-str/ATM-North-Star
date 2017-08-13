#include <logon_inspector.h>

#include <logon_standard.h>

ATM::LogonStatus LogonInspector::InspectLoginString(const std::string& login) {
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

ATM::LogonStatus LogonInspector::InspectPasswordString(
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

bool LogonInspector::IsLoginShort(int login_length) const {
  return login_length < LogonStandard::MinLoginLength();
}

bool LogonInspector::IsLoginLong(int login_length) const {
  return login_length > LogonStandard::MaxLoginLength();
}

bool LogonInspector::IsPasswordShort(int password_length) const {
  return password_length < LogonStandard::PasswordLength();
}

bool LogonInspector::IsPasswordLong(int password_length) const {
  return password_length > LogonStandard::PasswordLength();
}

bool LogonInspector::IsPasswordContainSpaces() const {
  return string_analyzer_.AmountOfSpaces() > 0;
}

bool LogonInspector::IsStringContainSpecialSymbols() const {
  return string_analyzer_.IsStringContainSpecialSymbols();
}

bool LogonInspector::IsStringBeginWithSpace() const {
  return string_analyzer_.IsStringBeginWithSpace();
}

bool LogonInspector::IsStringEndWithSpace() const {
  return string_analyzer_.IsStringEndWithSpace();
}

bool LogonInspector::IsStringContainAdjacentSpaces() const {
  return string_analyzer_.IsStringContainAdjacentSpaces();
}

bool LogonInspector::IsStringContainOnlyDigits() const {
  return string_analyzer_.IsStringContainOnlyDigits();
}

bool LogonInspector::IsStringEmpty() const {
  return string_analyzer_.IsStringEmpty();
}
