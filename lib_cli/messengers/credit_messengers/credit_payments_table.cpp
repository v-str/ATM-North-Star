#include <credit_payments_table.h>

#include <iomanip>
#include <sstream>

#include <console_editor.h>

void CreditPaymentsTable::BuildCreditTable(
    int amount_of_months,
    double monthly_payment,
    const std::vector<double>& sum_of_owed_credit,
    const std::vector<double>& sum_of_interest_charges,
    const std::vector<double>& sum_of_main_debt_payment) const {
  DisplayTableTitles();
  for (int i = 1; i <= amount_of_months; ++i) {
  }
}

void CreditPaymentsTable::DisplayTableTitles() const {
  std::string numbers_of_payment = AlignCell(4, "#N");
  std::string monthly_payment = AlignCell(kCellSize, "Monthly payment");
  std::string credit_sum = AlignCell(kCellSize, "Sum of credit");
  std::string interest_charges = AlignCell(kCellSize, "Interest charges");
  std::string main_debt_payment = AlignCell(kCellSize, "Main debt payment");

  ConsoleEditor::WriteText("\n\n" + numbers_of_payment + monthly_payment +
                           credit_sum + interest_charges + main_debt_payment +
                           "\n\n");
  ConsoleEditor::IgnoreCinLine();
}

std::string CreditPaymentsTable::AlignCell(
    int cell_size, const std::string& string_content) const {
  int string_content_size = string_content.size();
  int spaces_before_string = cell_size - string_content_size - 1;

  std::string aligned_string;
  aligned_string.assign(spaces_before_string, ' ');
  aligned_string += string_content;
  aligned_string += " |";

  return aligned_string;
}

std::string CreditPaymentsTable::ConvertToString(double value) const {
  std::stringstream conversion_stream;
  conversion_stream << std::fixed << std::setprecision(2) << value;

  return conversion_stream.str();
}
