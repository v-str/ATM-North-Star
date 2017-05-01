#ifndef ATM_USER_H
#define ATM_USER_H

#include "cash_data.h"
#include "credit_data.h"
#include "identification_data.h"

class AtmUser {
 public:
  AtmUser();
  ~AtmUser();

 private:
  IdentificationData* identification_data_ = nullptr;
  CashData* cash_data_ = nullptr;
  CreditData* credit_data_ = nullptr;
};

#endif  // ATM_USER_H
