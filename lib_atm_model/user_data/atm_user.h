#ifndef ATM_USER_H
#define ATM_USER_H

#include <string>

#include <cash_data.h>
#include <identification_data.h>

class AtmUser {
 public:
  void SetLogin(const std::string& login);
  void SetPassword(const std::string& password);

  void SetCash(double cash);
  void AddCash(double cash);
  void WithdrawCash(double cash);

  void ResetData();

  std::string Login() const;
  std::string Password() const;
  double Cash() const;

 private:
  IdentificationData identification_data_;
  CashData cash_data_;
};

#endif  // ATM_USER_H
