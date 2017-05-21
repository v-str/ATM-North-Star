#ifndef REGISTRATION_VERIFICATOR_H
#define REGISTRATION_VERIFICATOR_H

#include <string>

#include <registration_status.h>
#include <string_analyzer.h>

class RegistrationInspector {
 public:
  ATM::LoginStatus InspectLoginString(const std::string& login);

 private:
  bool IsLoginShort(const std::string& login) const;
  bool IsLoginLong(const std::string& login) const;
  bool IsStringContainSpecialSymbols() const;
  bool IsStringBeginWithSpace() const;
  bool IsStringEndWithSpace() const;
  bool IsStringContainAdjacentSpaces() const;
  bool IsStringContainOnlyDigits() const;

  StringAnalyzer string_analyzer_;
};

#endif  // REGISTRATION_VERIFICATOR_H
