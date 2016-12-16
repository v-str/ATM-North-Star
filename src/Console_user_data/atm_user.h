#ifndef ATMUSER_H
#define ATMUSER_H

#include "cash_operator.h"
#include "user_identifier.h"

#include <memory>

class AtmUser
{
public:
    AtmUser();

    void SetLogin(const std::string &login);
    void SetPassord(const std::string &password);
    void SetCash(int cash);
    void SetCredit(int credit);
    void SetMonthlyPayment(double monthly_payment);
    void SetAmountOfCreditMonth(int amount_credit_month);



private:

    std::unique_ptr<CashOperator> cash_operator_;
    std::unique_ptr<UserIdentifier> user_identifier_;

};

#endif // ATMUSER_H
