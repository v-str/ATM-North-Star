#ifndef PRIMARY_CREDIT_OPERATIONS_H
#define PRIMARY_CREDIT_OPERATIONS_H

#include <string>

#include "cash_operator.h"
#include "credit_messenger.h"
#include "credit_offer.h"
#include "notice_about_error.h"
#include "secondary_credit_operations.h"
#include "system_utility.h"
#include "user_choice.h"
#include "user_identifier.h"

typedef int credit;

class PrimaryCreditOperations {
  using string = std::string;

  enum CreditSolution { kEnroll = 1, kRepeal, kExit };

 public:
  bool GetCreditData(CashOperator &cash_operator, const string &user_login,
                     const credit maximal_sum_of_credit,
                     const credit credit_mode);

 private:
  credit GetSumOfCredit(const credit maximal_sum_of_credit,
                        const credit credit_mode);

  credit GetMonthOfCredit(CashOperator &cash_operator);
  double CalculateMonthlePayment(const credit sum_of_credit,
                                 const credit amount_of_credit_months);

  NoticeAboutError error_operation_;
  SystemUtility utility_;
  CreditMessanger credit_messenger_;
  SecondaryCreditOperations secondary_credit_operation_;
  UserChoice user_choice_;
  CreditOffer credit_offer_;
};

#endif  // PRIMARY_CREDIT_OPERATIONS_H

// Метод GetCreditData:
//
// Получить сумму кредита
// Получить количество месяцев кредита

// Показать заголовок кредитного листа
// Расчитать ежемесячный платеж
// Вывести на экран предложение о подтверждении кредита
// Вернуть результат предложения взятия кредита

















