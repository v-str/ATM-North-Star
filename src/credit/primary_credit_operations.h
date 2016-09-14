#ifndef PRIMARY_CREDIT_OPERATIONS_H
#define PRIMARY_CREDIT_OPERATIONS_H

#include "notice_about_error.h"
#include "system_utility.h"
#include "user_identifier.h"

class PrimaryCreditOperations {
 public:
  double CalculateCredit(const int sum, const int amount_of_months);

 private:
  NoticeAboutError error_;
  SystemUtility utility_;
};

#endif  // PRIMARY_CREDIT_OPERATIONS_H
