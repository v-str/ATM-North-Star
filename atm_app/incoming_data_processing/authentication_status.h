#ifndef AUTHENTIFICATION_STATUS_H
#define AUTHENTIFICATION_STATUS_H

namespace ATM {
enum AuthenticationStatus {
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

#endif  // AUTHENTIFICATION_STATUS_H
