#ifndef ACCOUNT_INFORMATOR_H
#define ACCOUNT_INFORMATOR_H

#include <string>

#include <atm_user.h>

class AccountInformator {
 public:
  AccountInformator();

  void UpdataUserData(const AtmUser& user);

  std::string Login() const;
  std::string Cash() const;
  std::string CreditSum() const;
  std::string CreditTerm() const;
  std::string InterestRate() const;
  std::string MonthlyPayment() const;

 private:
  std::string login_;
  std::string cash_;
  std::string credit_sum_;
  std::string credit_term_;
  std::string interest_rate_;
  std::string monthly_payment_;
};

#endif  // ACCOUNT_INFORMATOR_H
