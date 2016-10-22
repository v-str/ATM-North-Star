#ifndef CREDIT_OFFER_H
#define CREDIT_OFFER_H

#include "cash_operator.h"
#include "credit_messenger.h"
#include "credit_page.h"
#include "notifier.h"
#include "secondary_credit_operations.h"
#include "user_choice.h"

class CreditOffer {
  enum CreditSolution { kEnroll = 1, kRepeal, kExit };

 public:
  void SuggestACredit(CashOperator &cash_operator,
                      const std::string &user_login, int sum_of_credit,
                      int amount_of_months) const;

 private:
  int GetCreditChoice() const;

  void DoCreditOperation(CashOperator &cash_operator, int sum_of_credit,
                         double pay_per_month) const;
  void DoCreditOperation(CashOperator &cash_operator) const;
  void DoCreditOperation(CashOperator &cash_operator,
                         Notifier error_operation) const;

  Notifier error_operation_;
  CreditMessanger credit_messenger_;
  UserChoice user_choice_;
  SecondaryCreditOperations secondary_credit_operation_;
  CreditPage credit_page_;
};

#endif  // CREDIT_OFFER_H
