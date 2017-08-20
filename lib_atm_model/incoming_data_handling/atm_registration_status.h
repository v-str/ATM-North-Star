#ifndef ATM_REGISTRATION_STATUS_H
#define ATM_REGISTRATION_STATUS_H

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

#endif  // ATM_REGISTRATION_STATUS_H
