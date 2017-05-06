#include "atm.h"

#include <user_registrator.h>

void Atm::RegisterUser(const std::string& login, const std::string& password) {
  UserRegistrator::RegisterUser(&user_, login, password);
}

const std::string Atm::AccountInfo(Atm::AccountData account_data) {
  account_informator_.UpdataUserData(user_);
  switch (account_data) {
    case kLogin:
      return account_informator_.Login();
    case kCash:
      return account_informator_.Cash();
    case kCreditSum:
      return account_informator_.CreditSum();
    case kCreditTerm:
      return account_informator_.CreditTerm();
    case kInterestRate:
      return account_informator_.InterestRate();
    case kMonthlyPayment:
      return account_informator_.MonthlyPayment();
  }
}
