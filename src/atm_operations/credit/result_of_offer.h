#ifndef RESULT_OF_OFFER_H
#define RESULT_OF_OFFER_H

#include "cash_operator.h"
#include "credit_messenger.h"
#include "notice_about_error.h"
#include "user_input.h"

class ResultOfOffer {
  enum CreditSolution { kEnroll = 1, kRepeal, kExit };

 public:
  bool SuggestACredit(CashOperator &cash_operator, int choice,
                      int sum_of_credit, int pay_per_month) const;

 private:
  bool DoACreditOperation(CashOperator &cash_operator, int sum_of_credit,
                          int pay_per_month) const;
  bool DoACreditOperation(CashOperator &cash_operator) const;
  bool DoACreditOperation(CreditMessanger credit_messenger) const;
  bool DoACreditOperation(CashOperator &cash_operator,
                          NoticeAboutError error_operation) const;

  NoticeAboutError error_operation_;
  CreditMessanger credit_messenger_;
  UserInput user_input_;
};

#endif  // RESULT_OF_OFFER_H
