#ifndef CLI_CREDIT_DEPARTMENT_H
#define CLI_CREDIT_DEPARTMENT_H

#include "credit_department.h"
#include "credit_messenger.h"
#include "user_input.h"

class CLICreditDepartment : public CreditDepartment {
 public:
  void StartCreditOperationFor(AtmUser* user) override;

 protected:
  void SuggestCredit(AtmUser* user) override;

 private:
  CreditMessenger messenger_;
  CheckState state_;
};

#endif  // CLI_CREDIT_DEPARTMENT_H
