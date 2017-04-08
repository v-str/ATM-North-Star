#ifndef CREDIT_DEPARTMENT_H
#define CREDIT_DEPARTMENT_H

#include "credit_calculator.h"
#include "credit_check.h"
#include "credit_data.h"

#include "atm_user.h"

class CreditDepartment {
 public:
  virtual void StartCreditOperationFor(AtmUser* user) = 0;

 protected:
  int GetResultOfUserCheck(const AtmUser& user) const;

 private:
  CreditCalculator calculator_;
  CreditCheck checker_;
  CreditData credit_data_;
};

#endif  // CREDIT_DEPARTMENT_H
