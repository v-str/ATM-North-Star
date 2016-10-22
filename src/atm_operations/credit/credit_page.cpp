#include "credit_page.h"

void CreditPage::ShowTitle(const std::string &user_login,
                           const int sum_of_credit) const {
  credit_messenger_.ShowCreditTitle(user_login, sum_of_credit);
}
