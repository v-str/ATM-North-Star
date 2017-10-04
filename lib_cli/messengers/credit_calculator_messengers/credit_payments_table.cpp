#include <credit_payments_table.h>

#include <iomanip>
#include <sstream>

#include <console_editor.h>

std::string CreditPaymentsTable::kEmptyCell = "----------";
std::string CreditPaymentsTable::kSpace = "      ";
std::string CreditPaymentsTable::kLeftBorder = "|";

void CreditPaymentsTable::BuildCreditTable(
    int amount_of_months, double monthly_payment,
    const std::vector<std::string>& sum_of_owed_credit,
    const std::vector<std::string>& sum_of_interest_charges,
    const std::vector<std::string>& sum_of_main_debt_payment) const {
  DisplayTitle();
  for (int i = 0; i < amount_of_months; ++i) {
    DisplayCreditTableRow(i + 1, monthly_payment, sum_of_owed_credit[i],
                          sum_of_interest_charges[i],
                          sum_of_main_debt_payment[i]);
    ConsoleEditor::Sleep(kSleepMSec);
  }
  DisplayEmptyRow();
}

void CreditPaymentsTable::DisplayTotalLine(
    const std::string& total_monthly_payment_sum,
    const std::string& total_interest_charges_sum,
    const std::string& total_main_debt_payment) const {
  ConsoleEditor::WriteText(kLeftBorder + AlignCell(kCellSize, "Total:") +
                           AlignCell(kCellSize, total_monthly_payment_sum) +
                           AlignCell(kCellSize, "") +
                           AlignCell(kCellSize, total_interest_charges_sum) +
                           AlignCell(kCellSize, total_main_debt_payment));
  ConsoleEditor::AddEmptyLineNTimes(1);
  DisplayEmptyRow();
}

void CreditPaymentsTable::DisplayTitle() const {
  ConsoleEditor::AddEmptyLineNTimes(2);
  DisplayEmptyRow();
  DisplayUpperTitlesRow();
  DisplayLowerTitlesRow();
  DisplayEmptyRow();
}

void CreditPaymentsTable::DisplayUpperTitlesRow() const {
  std::string number_of = AlignCell(kCellSize, "Number of");
  std::string monthly = AlignCell(kCellSize, "Monthly");
  std::string sum_of = AlignCell(kCellSize, "Sum of");
  std::string interest = AlignCell(kCellSize, "Interest");
  std::string main_debt = AlignCell(kCellSize, "Main debt");

  ConsoleEditor::WriteText(kLeftBorder + number_of + monthly + sum_of +
                           interest + main_debt);
  ConsoleEditor::AddEmptyLineNTimes(1);
}

void CreditPaymentsTable::DisplayLowerTitlesRow() const {
  std::string payment = AlignCell(kCellSize, "payment");
  std::string credit = AlignCell(kCellSize, "credit");
  std::string charges = AlignCell(kCellSize, "charges");

  ConsoleEditor::WriteText(kLeftBorder + payment + payment + credit + charges +
                           payment);
  ConsoleEditor::AddEmptyLineNTimes(1);
}

void CreditPaymentsTable::DisplayEmptyRow() const {
  std::string empty_string;
  FillEmptyRow(&empty_string);
  ConsoleEditor::WriteText(kLeftBorder + empty_string);
  ConsoleEditor::AddEmptyLineNTimes(1);
}

void CreditPaymentsTable::FillEmptyRow(std::string* filling_string) const {
  for (int i = 0; i < kAmountOfColumns; ++i) {
    *filling_string += AlignCell(kCellSize, kEmptyCell);
  }
}

void CreditPaymentsTable::DisplayCreditTableRow(
    int number_of_month, double monthly_payment,
    const std::string& sum_of_owed_credit,
    const std::string& sum_of_interest_charge,
    const std::string& sum_of_main_debt_payment) const {
  std::string month_cell =
      AlignCell(kCellSize, std::to_string(number_of_month));
  std::string monthly_payment_cell =
      AlignCell(kCellSize, ConvertToString(monthly_payment));
  ConsoleEditor::WriteText(kLeftBorder + month_cell + monthly_payment_cell +
                           AlignCell(kCellSize, sum_of_owed_credit) +
                           AlignCell(kCellSize, sum_of_interest_charge) +
                           AlignCell(kCellSize, sum_of_main_debt_payment));
  ConsoleEditor::AddEmptyLineNTimes(1);
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
