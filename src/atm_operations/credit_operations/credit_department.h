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
  virtual void SuggestCredit(AtmUser* user) = 0;
  virtual bool ConsiderCredit(int user_cash) = 0;
  virtual void ShowCredit() = 0;

  int ResultOfUserCheck(const AtmUser& user) const;
  int MaxCreditSum(int cash);

  void SetCreditSum(int credit_sum);
  void SetCreditTerm(int months);
  void CalculateCredit();

  CreditData credit_data_;

 private:
  CreditCalculator calculator_;
  CreditCheck checker_;
};

#endif  // CREDIT_DEPARTMENT_H
