#include <credit_data_limiter.h>

CreditDataLimiter::CreditDataLimiter() {
  credit_sum_limit_ = std::make_pair<int, int>(10000, 500000);
  interest_rate_limit_ = std::make_pair<double, double>(5.0, 50.0);
  amount_of_months_limit_ = std::make_pair<int, int>(1, 60);
}
