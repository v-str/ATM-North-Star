#include "user_messenger.h"

static const int kMaxLenghtOfLogin = 21;
static const int kMaxLenghtOfPassword = 4;

UserMessenger::UserMessenger() {}

void UserMessenger::WriteSymbolsNTimes(char symbol, int n) const {
  for (int i = 0; i < n; ++i) {
    cout << symbol;
  }
}

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
  WriteSymbolsNTimes('-', 45);
  cout << "\n\t";
  utility_.WriteTextWithDelay(
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$");
  cout << "\t";
  WriteSymbolsNTimes('-', 45);
  cout << "\n";
  cout << "\t# Please enter the sum of money($): ";
}

void UserMessenger::ShowUserBalance(double balance) {
  cout << "\n\t";
  WriteSymbolsNTimes('-', 45);
  utility_.WriteTextWithDelay("\n\t# Balance refill completed successfully.");
  WriteUserInfo("Balance", std::to_string(balance));
  cout << "\n\t";
  cin.sync();
  utility_.Sleep(1000);
}

void UserMessenger::WriteUserInfo(const UserMessenger::string &info_title,
                                  const UserMessenger::string &value) {
  cout << "\n\t# " << info_title << ": " << value << "\n\t";
  WriteSymbolsNTimes('-', 45);
  utility_.Sleep(100);
}

void UserMessenger::ShowStatement(int cash, const string &spaces) const {
  cout << "\t##################\n"
          "\t#                #\n"
          "\t#  28 Green st.  #\n"
          "\t#   New - York   #\n"
          "\t#                #\n"
          "\t#   NORTH BANK   #\n"
          "\t#                #\n"
          "\t# Balance:       #\n"
          "\t#  $ "
       << cash << spaces << "#\n";
  cout << "\t#                #\n"
          "\t#  HAVE A NICE   #\n"
          "\t#      DAY       #\n"
          "\t#                #\n"
          "\t##################\n";
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
  WriteSymbolsNTimes('-', 45);

  WriteUserInfo("Login", user_identifier.GetLogin());
  WriteUserInfo("Password", user_identifier.GetPassword());
  WriteUserInfo("Balance", std::to_string(cash_operator.GetCash()));
  WriteUserInfo("Credit", std::to_string(cash_operator.GetCredit()));
  WriteUserInfo("Monthly payment $",
                std::to_string(cash_operator.GetMonthlyPayment()));
  WriteUserInfo("Credit term",
                std::to_string(cash_operator.GetAmountOfCreditMonth()));
}

void UserMessenger::ShowInitialLoginText() {
  cout << "\n\n\n\t\tLogin: ";

  WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
}

void UserMessenger::ShowInitialPasswordText() {
  cout << "\t\tPassword: XXXX\b\b\b\b";
  WriteSymbolsNTimes('X', kMaxLenghtOfPassword);
  WriteSymbolsNTimes('\b', kMaxLenghtOfPassword);
}
