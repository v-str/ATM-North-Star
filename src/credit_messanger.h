#ifndef CREDIT_MESSANGER_H
#define CREDIT_MESSANGER_H

#include "system_utility.h"

class CreditMessanger {
 public:
  CreditMessanger();

  void RefusToGrantAnotherCredit() const;

private:
  SystemUtility utility_;
};

#endif  // CREDIT_MESSANGER_H
