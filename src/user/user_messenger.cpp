#include "user_messenger.h"

static const int kMaxLenghtOfLogin = 21;
static const int kMaxLenghtOfPassword = 4;
static const int kFrame = 45;

UserMessenger::UserMessenger() {}

void UserMessenger::ShowRegistrationScreen() const {
  utility_.ClearScreen();

  cout << "\n\t\t   ********************\n"
          "\t\t   *   REGISTRATION   *\n"
          "\t\t   ********************\n";
}

void UserMessenger::ShowTransactionMenu() {
  utility_.ClearScreen();
  string select =
      "\n\t################ Transaction menu ##################\n"
      "\t#                                                  #\n"
      "\t# 1. Account information            2. Refill      #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 3. Credit application             4. Withdrawal  #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 5. Statement                      6. Exit        #\n"
      "\t#                                                  #\n"
      "\t####################################################\n";
  cout << select;
  cout << "\tSelect: ";
}

void UserMessenger::ShowNotifyAboutCash() {
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  cout << "\n\t";
  utility_.WriteTextWithDelay(
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$");
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  cout << "\n";
  cout << "\t# Please enter the sum of money($): ";
}

void UserMessenger::ShowIncorrectDataMessage() {
  utility_.WriteTextWithDelay(
      "\t Data is not correct, please reload the program.\n\n");
  cin.get();
}

void UserMessenger::ShowIncorrectMonthInput() {
  cout << "Number of credit month can't be more than 60\n";
  cout << "The number of months to repay the loan: ";
}

void UserMessenger::SuggestUserToExit() const {
  utility_.WriteTextWithDelay(
      "\n\t# Do you really want to exit?\n"
      "\t# 1. No, go to main\n"
      "\t# 2. Yes, exit\n");
  cout << "\t# Enter: ";
}

void UserMessenger::WishAGoodDay() const {
  cout << "\n\t####################\n"
          "\t#                  #\n"
          "\t# Have a nice day! #\n"
          "\t#                  #\n"
          "\t####################\n\n";
}

void UserMessenger::ShowTransactionMenu() const {
  string select =
      "\n\t################ Transaction menu ##################\n"
      "\t#                                                  #\n"
      "\t# 1. Account information            2. Refill      #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 3. Credit application             4. Withdrawal  #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 5. Statement                      6. Exit        #\n"
      "\t#                                                  #\n"
      "\t####################################################\n";
  cout << select;
}

void UserMessenger::ShowAccountInformation(UserIdentifier &user_identifier,
                                           CashOperator &cash_operator) {
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', kFrame);

  refill_messenger_.WriteUserInfo("Login", user_identifier.GetLogin());
  refill_messenger_.WriteUserInfo("Password", user_identifier.GetPassword());
  refill_messenger_.WriteUserInfo("Balance",
                                  std::to_string(cash_operator.GetCash()));
  refill_messenger_.WriteUserInfo("Credit",
                                  std::to_string(cash_operator.GetCredit()));
  refill_messenger_.WriteUserInfo(
      "Monthly payment $", std::to_string(cash_operator.GetMonthlyPayment()));
  refill_messenger_.WriteUserInfo(
      "Credit term", std::to_string(cash_operator.GetAmountOfCreditMonth()));
}

void UserMessenger::ShowInitialLoginText() const {
  cout << "\n\n\n\t\tLogin: ";

  utility_.WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  utility_.WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
}

void UserMessenger::ShowInitialPasswordText() const {
  cout << "\t\tPassword: XXXX\b\b\b\b";
  utility_.WriteSymbolsNTimes('X', kMaxLenghtOfPassword);
  utility_.WriteSymbolsNTimes('\b', kMaxLenghtOfPassword);
}

void UserMessenger::ShowSuggestionAboutExit() const {
  utility_.WriteTextWithDelay(
      "\n\t# 1. Exit to main page.\n"
      "\t# 2. Exit program.\n");
  cout << "\t# Enter: ";
}

void UserMessenger::ShowIncorrectSumInput() const {
  cout << "\t# Incorrect input, please try again:\n"
          "\t# Enter: ";
}

void UserMessenger::ShowIncorrectData() const {
  cout << "\n\tIncorrect data. Please, repeat.\n";
  cout << "\t-------------------------------\n";
  cout << "\tSelect: ";
}

void UserMessenger::ShowIncorrectInitialData() const {
  utility_.WriteTextWithDelay(
      "\n\tIncorrect input, "
      "\n\treload the program\n");
}
