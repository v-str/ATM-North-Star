#include <credit_messenger.h>

#include <console_editor.h>
#include <text_writer.h>

void CreditMessenger::RefuseACreditBasedOnAnotherCredit() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "# Sorry, but you have already credit in our bank.\n"
      "# You can't get a second credit, while your first\n"
      "# credit is not complete.\n");
}

void CreditMessenger::RefuseACreditBasedOnCash(int sum_of_cash) {
  ConsoleEditor::ClearScreen();

  ConsoleEditor::WriteTextWithInterrupt("# We checked your balance.\n",
                                        kHalfASecond);

  ConsoleEditor::WriteTextWithInterrupt(
      "# Available cash = $" + std::to_string(sum_of_cash) + "\n" +
          "# Sorry, for getting a credit your balance must be "
          "$1000 or more.\n",
      kHalfASecond);
}

void CreditMessenger::NotifyAboutCredit() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "# You can get a credit in our bank if your\n"
      "# balance more than $1000.\n"
      "# We draw your attention to the fact that\n"
      "# our bank may refuse you in getting a credit\n"
      "# without giving any reason.\n"
      "# Nowadays, all credits are set on 14% per year\n"
      "# The credit depend from sum on account at the moment.\n");

  ConsoleEditor::WriteText(
      "\n#####################\n"
      "#   Continue?       #\n"
      "#                   #\n"
      "#   1. Yes          #\n"
      "#   2. No           #\n"
      "#                   #\n"
      "#####################\n\n"
      "Enter: ");
}

void CreditMessenger::ShowCreditConditions(int maximal_sum_of_credit) {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithInterrupt(
      "# Your balance more than 1000$. You can afford to take the\n"
      "# credit in our bank. The maximal credit sum for you is:\n",
      kHalfASecond);

  ConsoleEditor::WriteSymbolsNTimes("-", 70);
  ConsoleEditor::WriteText("\n");
  ConsoleEditor::WriteText(" \t\t\t | $");
  std::string convertible_string_value = std::to_string(maximal_sum_of_credit);
  ConsoleEditor::WriteText(convertible_string_value);
  ConsoleEditor::WriteText(" |\n");
  ConsoleEditor::WriteSymbolsNTimes("-", 70);
  ConsoleEditor::WriteText("\n");

  ConsoleEditor::WriteTextWithInterrupt(
      "\n# Do you prefer get all sum or you want to change\nthe sum of "
      "credit?\n\n"
      "# 1. Get all sum\n"
      "# 2. Change the sum of credit\n"
      "# 3. Exit credit menu\n",
      kHalfASecond);
  ConsoleEditor::WriteText("# Enter: ");
}

void CreditMessenger::SuggestToConfirmACredit() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Do you confirm the credit?\n"
      "\t1. Yes, I confirm.\n"
      "\t2. Repeal a credit.\n"
      "\tEnter: ");
}

void CreditMessenger::EnrollACredit() {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "# The credit was successfully transferred on your account.\n"
      "# You might cash your credit in our nearest bank.\n");
}

void CreditMessenger::RepealACreadit() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Credit is repealed...\n");
}

void CreditMessenger::ShowInfoAboutCreditSum() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteSymbolsNTimes("-", 70);
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "The entered sum should:\n\n"
      "\t- not exceed the allowed credit.\n"
      "\t- be greater than minimal sum of credit equal $500.\n");
  ConsoleEditor::WriteSymbolsNTimes("-", 70);
}

void CreditMessenger::SuggestEnterCreditSum() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "Enter the desired sum of credit: $");
}

void CreditMessenger::ShowError(const std::string& error_message) {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteSymbolsNTimes(" . ", 20);
  ConsoleEditor::WriteText("\n    ");
  ConsoleEditor::WriteTextWithDelayPerSymbol("Error! " + error_message);
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteSymbolsNTimes(" . ", 20);
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::Sleep(500);
}

void CreditMessenger::ShowDataConfirmation() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteSymbolsNTimes(":", 20);
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteTextWithDelayPerSymbol(":: Data confirmed ::");
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteSymbolsNTimes(":", 20);
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::Sleep(750);
}

void CreditMessenger::ShowInfoAboutCreditTerm() {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::WriteSymbolsNTimes("-", 70);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\nThe entered credit term should:\n\n"
      "\t- not exceed 60 months ( 5 years )\n"
      "\t- be greater than minimal credit term equal 6 months.\n");
  ConsoleEditor::WriteSymbolsNTimes("-", 70);
}

void CreditMessenger::SuggestEnterCreditTerm() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "Enter the desired term of credit: $");
}

void CreditMessenger::ShowIncorrectCashInformation(int cash) {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteSymbolsNTimes("-", 65);
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteText(" Balance: $" + std::to_string(cash) + " ");
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteSymbolsNTimes("-", 65);
  ConsoleEditor::AddEmptyLineNTimes(1);
}

void CreditMessenger::UnavailableCreditState() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteSymbolsNTimes("#", 65);
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      " # Sorry, credit section is not available at the moment,\n"
      " # Try later . . .\n");
  ConsoleEditor::WriteSymbolsNTimes("#", 65);
  ConsoleEditor::AddEmptyLineNTimes(1);
}
