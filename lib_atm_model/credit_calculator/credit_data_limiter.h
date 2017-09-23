#ifndef CREDIT_DATA_LIMITER_H
#define CREDIT_DATA_LIMITER_H

#include <utility>

class CreditDataLimiter {
 public:
    CreditDataLimiter();
 private:
   std::pair<int, int> credit_sum_limit_;
   std::pair<double, double> interest_rate_limit_;
   std::pair<int, int> amount_of_months_limit_;
};

#endif  // CREDIT_DATA_LIMITER_H
