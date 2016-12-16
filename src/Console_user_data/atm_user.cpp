#include "atm_user.h"

AtmUser::AtmUser()
    : cash_operator_(new CashOperator), user_identifier_(new UserIdentifier) {}

void AtmUser::SetLogin(const std::string &login) {
  user_identifier_->SetLogin(login);
}
