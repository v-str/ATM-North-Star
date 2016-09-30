#include "credit_page.h"

void CreditPage::ShowTitle(const string &user_login,
                           const credit sum_of_credit) const {
  credit_messenger_.ShowCreditTitle(user_login, sum_of_credit);
}
