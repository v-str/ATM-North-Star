#ifndef REGISTRATION_STATUS_H
#define REGISTRATION_STATUS_H

namespace ATM {
enum LoginStatus {
  kCorrectLogin,
  kShortLogin,
  kLongLogin,
  kSpecialSymbols,
  kBeginWithSpace,
  kEndWithSpace,
  kAdjacentSpaces
};
}

#endif  // REGISTRATION_STATUS_H
