#include <description_text.h>

QString DescriptionText::kAccountInfo =
    "This section shows your account information. For example, it's look like "
    "this:\n\n"
    "Login: Mr. Anderson\n"
    "Cash $: 7700.0\n"
    "Credit $: 20000\n"
    "Monthly payment $: 2280\n"
    "Credit term: 20 month(s)";

QString DescriptionText::kCashRefill =
    "In this section user may refill balance on any sum from 10 to 50000 "
    "dollars. You can enter any sum such as 100 or 10705.66. When you refill "
    "on "
    "10705.66, it supposed, that you making a transfer from another account.";

QString DescriptionText::kCreditApp =
    "Our bank may allow you to get a credit in the amount of not more than 15x "
    "of your cash on account at the moment. For example:\n"
    "If your balance at the moment equal $2000, you may get a $30000 sum of "
    "credit on individual conditions.";

QString DescriptionText::kWithdrawal =
    "Withdrawal is executed from your existing account. Optionally, you can "
    "withdraw the all cash at once or choose the amount that you need.";

QString DescriptionText::kStatement =
    "Standart statement which contain information about your cash.\n";

QString DescriptionText::AccountInfoText() { return kAccountInfo; }

QString DescriptionText::CashRefillInfoText() { return kCashRefill; }

QString DescriptionText::CreditAppText() { return kCreditApp; }

QString DescriptionText::WithdrawalInfoText() { return kWithdrawal; }

QString DescriptionText::StatementIndoText() { return kStatement; }
