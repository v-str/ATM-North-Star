#include "primary_credit_operations.h"

double PrimaryCreditOperations::CalculateCredit(const int sum,
                                                const int amount_of_months) {
  double rate = (sum * 14) / 100;
  double pay_per_month = (sum / amount_of_months) + (rate / 12);
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
