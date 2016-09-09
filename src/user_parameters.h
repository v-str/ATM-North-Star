#ifndef USER_PARAMETERS_H
#define USER_PARAMETERS_H

#include <string>

struct AccountInfo{
  using string = std::string;

  string login_ = "no_name";
  string password_ = "0000";
  int cash_ = 0.0;
  double credit_ = 0.0;
  double monthly_payment_ = 0.0;
  int amount_of_credit_month_ = 0;
};

#endif  // USER_PARAMETERS_H
