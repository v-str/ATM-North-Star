#include <authenticator.h>

#include <registration_standard.h>

ATM::RegistrationStatus Authenticator::InspectLoginString(
    const std::string& login) {
  string_analyzer_.AnalyzeString(login);

  if (IsLoginShort(login.length())) {
    return ATM::RegistrationStatus::kShortLogin;
  }
  if (IsLoginLong(login.length())) {
    return ATM::RegistrationStatus::kLongLogin;
  }
  if (IsStringContainSpecialSymbols()) {
    return ATM::RegistrationStatus::kSpecialSymbols;
  }
  if (IsStringBeginWithSpace()) {
    return ATM::RegistrationStatus::kBeginWithSpace;
  }
  if (IsStringEndWithSpace()) {
    return ATM::RegistrationStatus::kEndWithSpace;
  }
  if (IsStringContainAdjacentSpaces()) {
    return ATM::RegistrationStatus::kAdjacentSpaces;
  }
  if (IsStringContainOnlyDigits()) {
    return ATM::RegistrationStatus::kContainOnlyDigits;
  }

  return ATM::RegistrationStatus::kCorrectLogin;
}

ATM::RegistrationStatus Authenticator::InspectPasswordString(
    const std::string& password) {
  string_analyzer_.AnalyzeString(password);

  if (IsPasswordShort(password.length())) {
    return ATM::RegistrationStatus::kShortPassword;
  }
  if (IsPasswordLong(password.length())) {
    return ATM::RegistrationStatus::kLongPassword;
  }
  if (IsPasswordContainSpaces()) {
    return ATM::RegistrationStatus::kContainSpaceSymbol;
  }
  if (IsStringContainSpecialSymbols()) {
    return ATM::RegistrationStatus::kSpecialSymbols;
  }

  return ATM::RegistrationStatus::kCorrectPassword;
}

bool Authenticator::IsLoginShort(int login_length) const {
  return login_length < RegistrationStandard::MinLoginLength();
}

bool Authenticator::IsLoginLong(int login_length) const {
  return login_length > RegistrationStandard::MaxLoginLength();
}

bool Authenticator::IsPasswordShort(int password_length) const {
  return password_length < RegistrationStandard::PasswordLength();
}

bool Authenticator::IsPasswordLong(int password_length) const {
  return password_length > RegistrationStandard::PasswordLength();
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
