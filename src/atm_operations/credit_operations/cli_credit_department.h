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
  enum CreditMenuItem { kMaxCreditSum = 1, kUserCreditSum, kExit };

  int GetCreditSumFromUser(int max_credit_sum) const;
  int GetCreditTermFromUser() const;

  bool IsValid(int comparable_variable,
               int condition_1,
               int condition_2,
               int condition_3,
               const std::string& phrase_1,
               const std::string& phrase_2) const;

  void PerformCreditCalculations(int credit_sum);

  CreditMessenger messenger_;
  UserInput input_;

  const int kConsiderCredit = 1;
};

#endif  // CLI_CREDIT_DEPARTMENT_H
