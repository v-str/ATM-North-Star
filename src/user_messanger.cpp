#include "user_messanger.h"

static const int kMaxLenghtOfLogin = 21;

UserMessanger::UserMessanger() {}

void UserMessanger::WriteSymbolsNTimes(char symbol, int n) const {
  for (int i = 0; i < n; ++i) {
    cout << symbol;
  }
}

void UserMessanger::ShowRegistrationScreen() {
  utility_.ClearScreen();

  cout << "\n\t\t   ********************\n"
          "\t\t   *   REGISTRATION   *\n"
          "\t\t   ********************\n";
}

void UserMessanger::ShowIncorrectLoginMessage() {
  utility_.ClearScreen();
  cout << "\n\n\n\n\t|---------------------------|\n";
  utility_.WriteTextWithDelay(
      "\t|Incorrect login.           |\n"
      "\t|It must be more than 1 and |\n"
      "\t|less than 20 symbols.      |\n"
      "\t|Please, reload the program.|");
  cout << "\t|---------------------------|\n\n";
}

void UserMessanger::ShowIncorrectPasswordMessage() {
  utility_.ClearScreen();
  cout << "\n\n\n\n\t|---------------------------|\n";
  utility_.WriteTextWithDelay(
      "\t|Incorrect password.        |\n"
      "\t|It must be in XXXX format. |\n"
      "\t|Please, reload the program.|");
  cout << "\t|---------------------------|\n\n\t\t\t";
}

void UserMessanger::ShowTransactionMenu() {
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

void UserMessanger::ShowNotifyAboutCash() {
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

void UserMessanger::ShowUserBalance(double balance) {
  cout << "\n\t";
  WriteSymbolsNTimes('-', 45);
  utility_.WriteTextWithDelay("\n\t# Balance refill completed successfully.");
  WriteUserInfo("Balance", std::to_string(balance));
  cout << "\n\t";
  cin.sync();
  utility_.Sleep(1000);
}

void UserMessanger::ShowIncorrectSum() {
  cout << "\n\tIncorrect sum, Reconnect to repeat.\n"
          "\t\t - Press any key - \n\n";
  cin.clear();
}

void UserMessanger::WriteUserInfo(const UserMessanger::string &info_title,
                                  const UserMessanger::string &value) {
  cout << "\n\t# " << info_title << ": " << value << "\n\t";
  WriteSymbolsNTimes('-', 45);
  utility_.Sleep(100);
}

void UserMessanger::ShowAccountInfo(const AccountInfo &account_info) {
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

int UserMessanger::SumOfWithdrawal() const {
  cout << "\n\t# Please, enter the required sum: ";

  double credit_sum = 0.0;
  cin >> credit_sum;

  return credit_sum;
}

void UserMessanger::ShowIncorrectWithdrawalSum(const AccountInfo &account_info,
                                               int incorrect_sum) {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay("\n\t Sorry, entered sum is incorrect.\n\n");
  cout << "\t Entered sum: " << incorrect_sum << "\n\n";
  WriteUserInfo("Balance", std::to_string(account_info.cash_));
  cin.clear();
}

UserMessanger::string UserMessanger::GetPasswordFromUser() {
  string password;
  cin >> password;
  return password;
}

void UserMessanger::ShowSumOfCash(int sum_of_cash) const {
  cout << "\t#Sum($): " << sum_of_cash << "\n";
  cout << "\t# Please enter your password: XXXX\b\b\b\b";
}

void UserMessanger::ShowSuccessfulWithdrawal(int sum_of_cash, int sum_of_withdrawal) {
  utility_.WriteTextWithDelay("\n\t# Withdrawal completed successfully\n");
  cout << "\t# Sum($): " << sum_of_cash << "\n";
  cout << "\t# Balance($): " << sum_of_withdrawal << "\n\n";
}

void UserMessanger::ShowIncorrectWithdrawalPasswordMessage()
{
    utility_.ClearScreen();
    utility_.WriteTextWithDelay(
        "\n\t# Sorry, entered password is incorrect.\n");
}
