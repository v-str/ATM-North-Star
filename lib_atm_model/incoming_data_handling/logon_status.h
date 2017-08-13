#ifndef LOGON_STATUS_H
#define LOGON_STATUS_H

namespace ATM {
enum LogonStatus {
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

#endif  // LOGON_STATUS_H
