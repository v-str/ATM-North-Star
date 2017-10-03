#include <atm_user.h>

void AtmUser::SetLogin(const std::string& login) {
  identification_data_.SetLogin(login);
}

void AtmUser::SetPassword(const std::string& password) {
  identification_data_.SetPassword(password);
}

void AtmUser::SetCash(double cash) { cash_data_.SetCash(cash); }

void AtmUser::AddCash(double cash) { cash_data_.AddCash(cash); }

void AtmUser::WithdrawCash(double cash) { cash_data_.WithdrawCash(cash); }

void AtmUser::ResetData() {
  SetLogin("");
  SetPassword("");
  SetCash(0.0);
}

std::string AtmUser::Login() const { return identification_data_.Login(); }

std::string AtmUser::Password() const {
  return identification_data_.Password();
}

double AtmUser::Cash() const { return cash_data_.Cash(); }
