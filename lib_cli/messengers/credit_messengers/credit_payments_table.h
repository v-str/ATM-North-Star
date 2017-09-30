#ifndef CREDIT_PAYMENTS_TABLE_H
#define CREDIT_PAYMENTS_TABLE_H

#include <string>
#include <vector>

class CreditPaymentsTable {
 public:
  void BuildCreditTable(
      int amount_of_months,
      double monthly_payment,
      const std::vector<double>& sum_of_owed_credit,
      const std::vector<double>& sum_of_interest_charges,
      const std::vector<double>& sum_of_main_debt_payment) const;

 private:
  void DisplayTableTitles() const;
  std::string AlignCell(int cell_size, const std::string& string_content) const;
  std::string ConvertToString(double value) const;

  static const int kCellSize = 20;
};

#endif  // CREDIT_PAYMENTS_TABLE_H
