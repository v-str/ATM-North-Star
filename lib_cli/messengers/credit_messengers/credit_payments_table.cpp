#include <credit_payments_table.h>

#include <iomanip>
#include <sstream>

#include <console_editor.h>

void CreditPaymentsTable::BuildCreditTable(
    double monthly_payment,
    int amount_of_months,
    const std::vector<double>& sum_of_owed_credit,
    const std::vector<double>& sum_of_interest_charges,
    const std::vector<double>& sum_of_main_debt_payment) {
  for (int i = 1; i <= amount_of_months; ++i) {
  }
}

std::string CreditPaymentsTable::AlignCell(int cell_size,
                                           const std::string& string_content) {
  int string_content_size = string_content.size();
  int spaces_before_string = cell_size - string_content_size - 1;

  std::string aligned_string(spaces_before_string, ' ');
  aligned_string += string_content;
  aligned_string += " ";

  return aligned_string;
}

std::string CreditPaymentsTable::ConvertToString(double value) {
  std::stringstream conversion_stream;
  conversion_stream << std::fixed << std::setprecision(2) << value;

  return conversion_stream.str();
}
