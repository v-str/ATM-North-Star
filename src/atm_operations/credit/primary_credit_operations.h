#ifndef PRIMARY_CREDIT_OPERATIONS_H
#define PRIMARY_CREDIT_OPERATIONS_H

#include <string>

#include "cash_operator.h"
#include "credit_messenger.h"
#include "notice_about_error.h"
#include "result_of_offer.h"
#include "secondary_credit_operations.h"
#include "system_utility.h"
#include "user_choice.h"
#include "user_identifier.h"

typedef int credit;

class PrimaryCreditOperations {
  using string = std::string;

  enum CreditSolution { kEnroll = 1, kRepeal, kExit };

 public:
  bool CollectCreditData(CashOperator &cash_operator, const string &user_login,
                         const credit maximal_sum_of_credit,
                         const credit credit_mode);

 private:
  credit GetSumOfCredit(const credit maximal_sum_of_credit,
                        const credit credit_mode);

  credit GetMonthOfCredit(CashOperator &cash_operator);
  double GetMonthlyCreditPayment(const credit sum_of_credit,
                                 const credit amount_of_credit_months);

  NoticeAboutError error_operation_;
  SystemUtility utility_;
  CreditMessanger credit_messenger_;
  SecondaryCreditOperations secondary_credit_operation_;
  UserChoice user_choice_;
  ResultOfOffer result_of_offer_;
};

#endif  // PRIMARY_CREDIT_OPERATIONS_H

// Метод CollectCreditData:
//
// Получить сумму кредита
// Получить количество месяцев кредита
// Присвоить пользователю полученное количество месяцев
// Очистить экран
// Показать информацию о выбранном кредите
// Получить ежемесячный платеж
// Вывести на экран предложение о взятии кредита
// Вернуть результат предложения взятия кредита
