#ifndef USER_CREDIT_H
#define USER_CREDIT_H

#include <iostream>

#include <string>
#include "system_utility.h"

using std::cout;
using std::cin;

class UserCredit {
  using string = std::string;

 public:
  UserCredit();

  double CalculateCredit(int sum, int amount_of_months);
  int GetIndividualSumOfCreditFromUser(int maximal_sum_of_credit);

 private:
  SystemUtility utility_;
};

#endif  // USER_CREDIT_H
