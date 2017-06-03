#include <authenticator.h>

#include <authentication_standard.h>

ATM::AuthenticationStatus Authenticator::InspectLoginString(
    const std::string& login) {
  string_analyzer_.AnalyzeString(login);

  if (IsLoginShort(login.length())) {
    return ATM::AuthenticationStatus::kShortLogin;
  }
  if (IsLoginLong(login.length())) {
    return ATM::AuthenticationStatus::kLongLogin;
  }
  if (IsStringContainSpecialSymbols()) {
    return ATM::AuthenticationStatus::kSpecialSymbols;
  }
  if (IsStringBeginWithSpace()) {
    return ATM::AuthenticationStatus::kBeginWithSpace;
  }
  if (IsStringEndWithSpace()) {
    return ATM::AuthenticationStatus::kEndWithSpace;
  }
  if (IsStringContainAdjacentSpaces()) {
    return ATM::AuthenticationStatus::kAdjacentSpaces;
  }
  if (IsStringContainOnlyDigits()) {
    return ATM::AuthenticationStatus::kContainOnlyDigits;
  }
  if (IsStringEmpty()) {
    return ATM::AuthenticationStatus::kEmptyString;
  }

  return ATM::AuthenticationStatus::kCorrectLogin;
}

ATM::AuthenticationStatus Authenticator::InspectPasswordString(
    const std::string& password) {
  string_analyzer_.AnalyzeString(password);

  if (IsPasswordShort(password.length())) {
    return ATM::AuthenticationStatus::kShortPassword;
  }
  if (IsPasswordLong(password.length())) {
    return ATM::AuthenticationStatus::kLongPassword;
  }
  if (IsPasswordContainSpaces()) {
    return ATM::AuthenticationStatus::kContainSpaceSymbol;
  }
  if (IsStringContainSpecialSymbols()) {
    return ATM::AuthenticationStatus::kSpecialSymbols;
  }
  if (IsStringEmpty()) {
    return ATM::AuthenticationStatus::kEmptyString;
  }

  return ATM::AuthenticationStatus::kCorrectPassword;
}

bool Authenticator::IsLoginShort(int login_length) const {
  return login_length < AuthenticationStandard::MinLoginLength();
}

bool Authenticator::IsLoginLong(int login_length) const {
  return login_length > AuthenticationStandard::MaxLoginLength();
}

bool Authenticator::IsPasswordShort(int password_length) const {
  return password_length < AuthenticationStandard::PasswordLength();
}

bool Authenticator::IsPasswordLong(int password_length) const {
  return password_length > AuthenticationStandard::PasswordLength();
}

bool Authenticator::IsPasswordContainSpaces() const {
  return string_analyzer_.AmountOfSpaces() > 0;
}

bool Authenticator::IsStringContainSpecialSymbols() const {
  return string_analyzer_.IsStringContainSpecialSymbols();
}

bool Authenticator::IsStringBeginWithSpace() const {
  return string_analyzer_.IsStringBeginWithSpace();
}

bool Authenticator::IsStringEndWithSpace() const {
  return string_analyzer_.IsStringEndWithSpace();
}

bool Authenticator::IsStringContainAdjacentSpaces() const {
  return string_analyzer_.IsStringContainAdjacentSpaces();
}

bool Authenticator::IsStringContainOnlyDigits() const {
  return string_analyzer_.IsStringContainOnlyDigits();
}

bool Authenticator::IsStringEmpty() const {
  return string_analyzer_.IsStringEmpty();
}
