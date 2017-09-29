#include <credit_payments_table.h>

#include <iomanip>
#include <sstream>

void CreditPaymentsTable::BuildCreditTable(
    const std::vector<double>& sum_of_owed_credit,
    const std::vector<double>& sum_of_interest_charges,
    const std::vector<double>& sum_of_main_debt_payment,
    double monthly_payment,
    int amount_of_months) {
  for (int i = 1; i <= amount_of_months; ++i) {
  }
}

std::string CreditPaymentsTable::AlignCell(const std::string& string_content) {}

std::string CreditPaymentsTable::ConvertToString(double value) {
  std::stringstream conversion_stream;
  conversion_stream << std::fixed << std::setprecision(2) << value;

  return conversion_stream.str();
}
