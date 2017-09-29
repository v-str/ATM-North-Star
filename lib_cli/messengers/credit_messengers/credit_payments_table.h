#ifndef CREDIT_PAYMENTS_TABLE_H
#define CREDIT_PAYMENTS_TABLE_H

#include <string>
#include <vector>

class CreditPaymentsTable {
 public:
  void BuildCreditTable(const std::vector<double>& sum_of_owed_credit,
                        const std::vector<double>& sum_of_interest_charges,
                        const std::vector<double>& sum_of_main_debt_payment,
                        double monthly_payment,
                        int amount_of_months);

 private:
  std::string AlignCell(const std::string& string_content);
  std::string ConvertToString(double value);

  static const int kCellMargin = 12;
};

#endif  // CREDIT_PAYMENTS_TABLE_H
