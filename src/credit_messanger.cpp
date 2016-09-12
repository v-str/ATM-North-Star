#include "credit_messanger.h"

CreditMessanger::CreditMessanger()
{

}

void CreditMessanger::RefusToGrantAnotherCredit() const
{
    utility_.WriteTextWithDelay(
        "\n #Sorry, but you have already a "
        "loan in our bank.\n"
        " #You can't get a second loan, "
        "while your first loan "
        "not complete.\n");
}
