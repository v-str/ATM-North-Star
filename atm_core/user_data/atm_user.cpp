#include "atm_user.h"

AtmUser::AtmUser()
    : identification_data_(new IdentificationData),
      cash_data_(new CashData),
      credit_data_(new CreditData) {}

AtmUser::~AtmUser() {
  delete identification_data_;
  delete cash_data_;
  delete credit_data_;
}
