#ifndef REGISTRATION_REPORTER_H
#define REGISTRATION_REPORTER_H

class RegistrationReporter {
 public:
  enum RegistrationStatus {
    kCorrectLogin,
    kShortLogin,
    kLongLogin,
    kCorrectPassword,
    kShortPassword,
    kLongPassword,
    kSpecialSymbols,
    kBeginWithSpace,
    kEndWithSpace,
    kAdjacentSpaces,
    kContainOnlyDigits,
    kContainSpaceSymbol,
    kEmptyString
  };

  void ShowLoginReport(RegistrationStatus login_status);
  void ShowPasswordReport(RegistrationStatus password_status);
};

#endif  // REGISTRATION_REPORTER_H
