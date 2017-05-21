#ifndef REGISTRATION_STATUS_H
#define REGISTRATION_STATUS_H

namespace ATM {
enum RegistrationStatus {
  kCorrectLogin,
  kShortLogin,
  kLongLogin,
  kSpecialSymbols,
  kBeginWithSpace,
  kEndWithSpace,
  kAdjacentSpaces,
  kContainOnlyDigits,
  kShortPassword,
  kLongPassword
};
}

#endif  // REGISTRATION_STATUS_H
