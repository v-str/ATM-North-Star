#include "account_informator.h"

void AccountInformator::DisplayAccountInformation(
    UserIdentifier &user_identifier, CashOperator &cash_operator) {
  //  screen_.DisplayStrip();
  //  screen_.DisplayLogin(user_identifier.GetLogin());
  //  screen_.DisplayPassword(user_identifier.GetPassword());
  //  screen_.DisplayCash(cash_operator.GetCash());
  //  screen_.DisplayCredit(cash_operator.GetCredit());
  //  screen_.DisplayPayment(cash_operator.GetMonthlyPayment());
  //  screen_.DispalyCreditMonth(cash_operator.GetAmountOfCreditMonth());

  account_messenger_.DisplayStrip();

  account_messenger_.DisplayUserInformation(account_messenger_.LoginText(),
                                            user_identifier.GetLogin());

  account_messenger_.DisplayUserInformation(account_messenger_.PasswordText(),
                                            user_identifier.GetPassword());

  account_messenger_.DisplayUserInformation(
      account_messenger_.BalanceText(),
      std::to_string(cash_operator.GetCash()));

  account_messenger_.DisplayUserInformation(
      account_messenger_.CreditText(),
      std::to_string(cash_operator.GetCredit()));

  account_messenger_.DisplayUserInformation(
      account_messenger_.PaymentText(),
      std::to_string(cash_operator.GetMonthlyPayment()));

  account_messenger_.DisplayUserInformation(
      account_messenger_.TermText(),
      std::to_string(cash_operator.GetAmountOfCreditMonth()));
}
