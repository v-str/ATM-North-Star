#include "user_messenger.h"

static const int kMaxLenghtOfLogin = 21;

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

void UserMessenger::ShowAccountInfo(const AccountInfo &account_info) {
  cout << "\t";
  WriteSymbolsNTimes('-', 45);

  WriteUserInfo("Login", account_info.login_);
  WriteUserInfo("Password", account_info.password_);
  WriteUserInfo("Balance", std::to_string(account_info.cash_));
  WriteUserInfo("Credit", std::to_string(account_info.credit_));
  WriteUserInfo("Monthly payment $",
                std::to_string(account_info.monthly_payment_));
  WriteUserInfo("Credit term",
                std::to_string(account_info.amount_of_credit_month_));
}

void UserMessenger::ShowSumOfWithdrawal(int sum_of_cash) const {
  cout << "\t#Sum($): " << sum_of_cash << "\n";
  cout << "\t# Please enter your password: XXXX\b\b\b\b";
}

void UserMessenger::ShowSuccessfulWithdrawal(int sum_of_cash,
                                             int sum_of_withdrawal) {
  utility_.WriteTextWithDelay("\n\t# Withdrawal completed successfully\n");
  cout << "\t# Sum($): " << sum_of_cash << "\n";
  cout << "\t# Balance($): " << sum_of_withdrawal << "\n\n";
}

void UserMessenger::ShowIncorrectPasswordMessage() {
  utility_.ClearScreen();
  utility_.IgnoreCinLine();
  utility_.WriteTextWithDelay("\n\t# Sorry, entered password is incorrect.\n");
}

void UserMessenger::ShowStatement(int cash, string &spaces) {
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
