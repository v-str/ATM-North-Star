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
  bool ConsiderCredit(int user_cash) override;
  void ShowCredit() override;

 private:
  enum CreditSum { kMaxCreditSum = 1, kUserCreditSum };

  int GetCreditSumFromUser(int max_credit_sum) const;
  int GetCreditTermFromUser() const;

  bool IsValid(int credit_sum, int max_credit_sum) const;

  void PerformCreditCalculations(int credit_sum);

  CreditMessenger messenger_;
  UserInput input_;

  const int kConsiderCredit = 1;
};

#endif  // CLI_CREDIT_DEPARTMENT_H
