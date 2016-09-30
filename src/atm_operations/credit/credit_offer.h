#ifndef CREDIT_OFFER_H
#define CREDIT_OFFER_H

#include "cash_operator.h"
#include "credit_messenger.h"
#include "credit_page.h"
#include "notice_about_error.h"
#include "secondary_credit_operations.h"
#include "user_choice.h"
#include "user_input.h"

class CreditOffer {
  enum CreditSolution { kEnroll = 1, kRepeal, kExit };

 public:
  bool SuggestACredit(CashOperator &cash_operator, const string &user_login,
                      int sum_of_credit, int months) const;

 private:
  int GetCreditChoice() const;

  bool DoACreditOperation(CashOperator &cash_operator, int sum_of_credit,
                          int pay_per_month) const;
  bool DoACreditOperation(CashOperator &cash_operator) const;
  bool DoACreditOperation(CreditMessanger credit_messenger) const;
  bool DoACreditOperation(CashOperator &cash_operator,
                          NoticeAboutError error_operation) const;

  NoticeAboutError error_operation_;
  CreditMessanger credit_messenger_;
  UserInput user_input_;
  UserChoice user_choice_;
  SecondaryCreditOperations secondary_credit_operation_;
  CreditPage credit_page_;
};

#endif  // CREDIT_OFFER_H
