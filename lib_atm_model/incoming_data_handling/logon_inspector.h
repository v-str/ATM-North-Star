#ifndef LOGON_INSPECTOR_H
#define LOGON_INSPECTOR_H

#include <string>

#include <logon_status.h>
#include <string_analyzer.h>

class LogonInspector {
 public:
  ATM::LogonStatus InspectLoginString(const std::string& login);
  ATM::LogonStatus InspectPasswordString(const std::string& password);

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

#endif  // LOGON_INSPECTOR_H
