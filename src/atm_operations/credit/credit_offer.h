#ifndef CREDIT_OFFER_H
#define CREDIT_OFFER_H

#include "cash_operator.h"
#include "credit_messenger.h"
#include "notice_about_error.h"
#include "user_choice.h"
#include "user_input.h"

typedef int credit;

class CreditOffer {
  enum CreditSolution { kEnroll = 1, kRepeal, kExit };

 public:
  bool SuggestACredit(CashOperator &cash_operator, credit sum_of_credit,
                      credit pay_per_month) const;

 private:
  credit GetCreditChoice() const;

  bool DoACreditOperation(CashOperator &cash_operator, credit sum_of_credit,
                          credit pay_per_month) const;
  bool DoACreditOperation(CashOperator &cash_operator) const;
  bool DoACreditOperation(CreditMessanger credit_messenger) const;
  bool DoACreditOperation(CashOperator &cash_operator,
                          NoticeAboutError error_operation) const;

  NoticeAboutError error_operation_;
  CreditMessanger credit_messenger_;
  UserInput user_input_;
  UserChoice user_choice_;
};

#endif  // CREDIT_OFFER_H
