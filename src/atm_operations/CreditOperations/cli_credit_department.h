#ifndef CLI_CREDIT_DEPARTMENT_H
#define CLI_CREDIT_DEPARTMENT_H

#include "credit_department.h"

class CLICreditDepartment : public CreditDepartment {
 public:
  CLICreditDepartment();

  void StartCreditOperation(AtmUser* user) override;
};

#endif  // CLI_CREDIT_DEPARTMENT_H
