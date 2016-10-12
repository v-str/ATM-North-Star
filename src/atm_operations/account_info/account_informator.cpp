#include "account_informator.h"

static const int N = 45;
static const int kSleep = 100;

void AccountInformator::DisplayAccountInformation(
    UserIdentifier &user_identifier, CashOperator &cash_operator) {
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', N);

  DisplayUserInformation("Login", user_identifier.GetLogin());
  DisplayUserInformation("Password", user_identifier.GetPassword());
  DisplayUserInformation("Balance", std::to_string(cash_operator.GetCash()));
  DisplayUserInformation("Credit", std::to_string(cash_operator.GetCredit()));
  DisplayUserInformation("Monthly payment $",
                         std::to_string(cash_operator.GetMonthlyPayment()));
  DisplayUserInformation(
      "Credit term", std::to_string(cash_operator.GetAmountOfCreditMonth()));
}

void AccountInformator::DisplayUserInformation(const std::string &info_title,
                                               const std::string &value) const {
  cout << "\n\t# " << info_title << ": " << value << "\n\t";
  utility_.WriteSymbolsNTimes('-', N);
  utility_.Sleep(kSleep);
}
