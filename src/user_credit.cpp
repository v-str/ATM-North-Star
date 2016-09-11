#include "user_credit.h"

UserCredit::UserCredit() {}

double UserCredit::CalculateCredit(int sum, int amount_of_months) {
  double x = (sum * 14) / 100;
  double pay_per_month = (sum / amount_of_months) + (x / 12);
  double all_payment = 0.0;
  for (int i = 0; i < amount_of_months; ++i) {
    cout << "\t* Payment month: " << i + 1 << "\tPayment sum: ";
    cout << pay_per_month << " $\n";
    utility_.Sleep(75);
    all_payment += pay_per_month;
  }
  cout << "\t\t\tTotal: " << all_payment << " $\n\n";
  return pay_per_month;
}

int UserCredit::GetIndividualSumOfCreditFromUser(int maximal_sum_of_credit) {
  int user_sum_of_credit = 0;
  do {
    utility_.WriteTextWithDelay(
        "The entered amount should not "
        "exceed the allowed credit.\n"
        "Enter the appropriate amount of credit: ");
    cout << "Enter: ";
    cin >> user_sum_of_credit;

    utility_.IgnoreCinLine();
  } while (user_sum_of_credit >= maximal_sum_of_credit);

  return user_sum_of_credit;
}

bool UserCredit::AlreadyHasACredit(AccountInfo &account_info) const {
  return account_info.credit_ > 0;
}
