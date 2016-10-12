#include "account_informator.h"

void AccountInformator::DisplayAccountInformation(
    UserIdentifier &user_identifier, CashOperator &cash_operator) {
  account_messenger_.DisplayStrip();

  account_messenger_.DisplayUserInformation(account_messenger_.GetLoginText(),
                                            user_identifier.GetLogin());

  account_messenger_.DisplayUserInformation(
      account_messenger_.GetPasswordText(), user_identifier.GetPassword());

  account_messenger_.DisplayUserInformation(
      account_messenger_.GetBalanceText(),
      std::to_string(cash_operator.GetCash()));

  account_messenger_.DisplayUserInformation(
      account_messenger_.GetCreditText(),
      std::to_string(cash_operator.GetCredit()));

  account_messenger_.DisplayUserInformation(
      account_messenger_.GetPaymentText(),
      std::to_string(cash_operator.GetMonthlyPayment()));

  account_messenger_.DisplayUserInformation(
      account_messenger_.GetTermText(),
      std::to_string(cash_operator.GetAmountOfCreditMonth()));
}
