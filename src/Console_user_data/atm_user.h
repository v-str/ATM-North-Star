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


private:

    std::unique_ptr<CashOperator> cash_operator_;
    std::unique_ptr<UserIdentifier> user_identifier_;

};

#endif // ATMUSER_H
