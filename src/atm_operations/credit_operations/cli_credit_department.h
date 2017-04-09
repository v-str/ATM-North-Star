#ifndef CLI_CREDIT_DEPARTMENT_H
#define CLI_CREDIT_DEPARTMENT_H

#include "credit_department.h"
#include "credit_messenger.h"

class CLICreditDepartment : public CreditDepartment {
 public:
  void StartCreditOperationFor(AtmUser* user) override;

 private:
  CreditMessenger messenger_;

  const int kPositiveCheck = 0;
  const int kCreditExist = 1;
  const int kInappropriateBalance = 2;
};

#endif  // CLI_CREDIT_DEPARTMENT_H
