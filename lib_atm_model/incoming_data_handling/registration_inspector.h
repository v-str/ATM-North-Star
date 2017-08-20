#ifndef REGISTRATION_INSPECTOR_H
#define REGISTRATION_INSPECTOR_H

#include <string>

#include <atm_registration_status.h>
#include <string_analyzer.h>

class RegistrationInspector {
 public:
  ATM::RegistrationStatus InspectLoginString(const std::string& login);
  ATM::RegistrationStatus InspectPasswordString(const std::string& password);

 private:
  bool IsLoginShort(int login_length) const;
  bool IsLoginLong(int login_length) const;

  bool IsPasswordShort(int password_length) const;
  bool IsPasswordLong(int password_length) const;
  bool IsPasswordContainSpaces() const;

  bool IsStringContainSpecialSymbols() const;
  bool IsStringBeginWithSpace() const;
  bool IsStringEndWithSpace() const;
  bool IsStringContainAdjacentSpaces() const;
  bool IsStringContainOnlyDigits() const;
  bool IsStringEmpty() const;

  StringAnalyzer string_analyzer_;
};

#endif  // REGISTRATION_INSPECTOR_H
