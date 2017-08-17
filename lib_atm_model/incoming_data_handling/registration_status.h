#ifndef REGISTRATION_STATUS_H
#define REGISTRATION_STATUS_H

namespace ATM {
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
}

#endif  // REGISTRATION_STATUS_H
