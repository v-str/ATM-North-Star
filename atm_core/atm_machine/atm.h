#ifndef ATM_h
#define ATM_h

#include <string>

#include <account_informator.h>
#include <atm_user.h>

class Atm {
 public:
  enum AccountData {
    kLogin,
    kCash,
    kCreditSum,
    kCreditTerm,
    kInterestRate,
    kMonthlyPayment
  };

  void RegisterUser(const std::string& login, const std::string& password);

  const std::string AccountInfo(Atm::AccountData account_data);
  const std::string Statement();

 private:
  AtmUser user_;
  AccountInformator account_informator_;
};

#endif  // ATM_h
