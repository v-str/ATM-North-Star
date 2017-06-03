#ifndef ACCOUNT_INFORMATOR_H
#define ACCOUNT_INFORMATOR_H

#include <string>

class AtmUser;

class AccountInformator {
 public:
  static void UpdataUserData(const AtmUser& user);

  static std::string Login();
  static std::string Cash();
  static std::string CreditSum();
  static std::string CreditTerm();
  static std::string InterestRate();
  static std::string MonthlyPayment();

 private:
  static std::string login_;
  static std::string cash_;
  static std::string credit_sum_;
  static std::string credit_term_;
  static std::string interest_rate_;
  static std::string monthly_payment_;
};

#endif  // ACCOUNT_INFORMATOR_H
