#ifndef CREDIT_PAYMENTS_TABLE_H
#define CREDIT_PAYMENTS_TABLE_H

#include <string>
#include <vector>

class CreditPaymentsTable {
 public:
  void BuildCreditTable(
      int amount_of_months,
      double monthly_payment,
      const std::vector<std::string>& sum_of_owed_credit,
      const std::vector<std::string>& sum_of_interest_charges,
      const std::vector<std::string>& sum_of_main_debt_payment) const;

  void DisplayTotalLine(const std::string& total_monthly_payment_sum,
                        const std::string& total_interest_charges_sum,
                        const std::string& total_main_debt_payment) const;

 private:
  void DisplayTitle() const;
  void DisplayUpperTitlesRow() const;
  void DisplayLowerTitlesRow() const;

  void DisplayEmptyRow() const;
  void FillEmptyRow(std::string* filling_string) const;

  void DisplayCreditTableRow(int number_of_month,
                             double monthly_payment,
                             const std::string& sum_of_owed_credit,
                             const std::string& sum_of_interest_charge,
                             const std::string& sum_of_main_debt_payment) const;
  std::string AlignCell(int cell_size, const std::string& string_content) const;
  std::string ConvertToString(double value) const;

  static std::string kEmptyCell;
  static std::string kSpace;
  static std::string kLeftBorder;

  static const int kCellSize = 12;
  static const int kSleepMSec = 50;
  static const int kAmountOfColumns = 5;
};

#endif  // CREDIT_PAYMENTS_TABLE_H
