#ifndef CREDIT_PAYMENTS_TABLE_H
#define CREDIT_PAYMENTS_TABLE_H

#include <string>
#include <vector>

class CreditPaymentsTable {
 public:
  void BuildCreditTable(double monthly_payment,
                        int amount_of_months,
                        const std::vector<double>& sum_of_owed_credit,
                        const std::vector<double>& sum_of_interest_charges,
                        const std::vector<double>& sum_of_main_debt_payment);

 private:
  void DisplayTablesTitles() const;

  std::string AlignCell(int cell_size, const std::string& string_content) const;
  std::string ConvertToString(double value) const;

  static const int kCellSize = 20;
};

#endif  // CREDIT_PAYMENTS_TABLE_H
