#include "user_messanger.h"

static const int kMaxLenghtOfLogin = 21;

UserMessanger::UserMessanger() {}

void UserMessanger::WriteSymbolsNTimes(char symbol, int n) const {
  for (int i = 0; i < n; ++i) {
    cout << symbol;
  }
}

void UserMessanger::ShowRegistrationScreen() const {
  utility_.ClearScreen();

  cout << "\n\t\t   ********************\n"
          "\t\t   *   REGISTRATION   *\n"
          "\t\t   ********************\n";
}

void UserMessanger::ShowIncorrectLoginMessage() const {
  utility_.ClearScreen();
  cout << "\n\n\n\n\t|---------------------------|\n";
  utility_.WriteTextWithDelay(
      "\t|Incorrect login.           |\n"
      "\t|It must be more than 1 and |\n"
      "\t|less than 20 symbols.      |\n"
      "\t|Please, reload the program.|");
  cout << "\t|---------------------------|\n\n";
}

void UserMessanger::ShowIncorrectFormatPasswordMessage() const {
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

void UserMessanger::ShowUnacceptableWithdrawal(const AccountInfo &account_info,
                                               int incorrect_sum) {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay("\n\t Sorry, entered sum is incorrect.\n\n");
  cout << "\t Entered sum: " << incorrect_sum << "\n\n";
  WriteUserInfo("Balance", std::to_string(account_info.cash_));
  utility_.IgnoreCinLine();
}

UserMessanger::string UserMessanger::GetPasswordFromUser() {
  string password;
  cin >> password;
  utility_.IgnoreCinLine();
  return password;
}

UserMessanger::string UserMessanger::SuggestToConfirmACredit() {
  string menu_text(
      "\n\t# Do you confirm the loan?\n"
      "\t1. Yes, I confirm.\n"
      "\t2. No, go to the main.\n"
      "\t3. Exit program.\n");

  return menu_text;
}

void UserMessanger::ShowSumOfWithdrawal(int sum_of_cash) const {
  cout << "\t#Sum($): " << sum_of_cash << "\n";
  cout << "\t# Please enter your password: XXXX\b\b\b\b";
}

void UserMessanger::ShowSuccessfulWithdrawal(int sum_of_cash,
                                             int sum_of_withdrawal) {
  utility_.WriteTextWithDelay("\n\t# Withdrawal completed successfully\n");
  cout << "\t# Sum($): " << sum_of_cash << "\n";
  cout << "\t# Balance($): " << sum_of_withdrawal << "\n\n";
}

void UserMessanger::ShowIncorrectPasswordMessage() {
  utility_.ClearScreen();
  utility_.IgnoreCinLine();
  utility_.WriteTextWithDelay("\n\t# Sorry, entered password is incorrect.\n");
}

void UserMessanger::ShowStatement(int cash, string &spaces) {
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

void UserMessanger::ShowIncorrectDataMessage() {
  utility_.WriteTextWithDelay(
      "\t Data is not correct, please reload the program.\n\n");
  cin.get();
}

void UserMessanger::ShowIncorrectMonthInput() {
  cout << "Number of credit month can't be more than 60\n";
  cout << "The number of months to repay the loan: ";
}

void UserMessanger::ShowNotifyAboutCredit() {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "# You can get a loan in our bank if your\n"
      "  balance more than $1000.\n"
      "# We draw your attention to the fact that\n"
      "  our bank may refuse you in getting a loan\n"
      "  without giving any reason.\n"
      "# Nowadays, the all loans are set on 14% per year\n"
      "# The loan depend from sum on account at the moment.\n");

  cout << "\n\t*********************\n"
          "\t*   Continue?       *\n"
          "\t*                   *\n"
          "\t*   1. Yes          *\n"
          "\t*   2. No           *\n"
          "\t*                   *\n"
          "\t*********************\n"
          "\tEnter: ";
}

void UserMessanger::ShowCreditConditions(int maximal_sum_of_credit) {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "# Your balance more than 1000$. You can afford to take the\n"
      "# credit in our bank. The maximum amount for you is:");
  utility_.Sleep(500);
  cout << "----------------------------------------------------------\n";
  cout << " \t\t\t $" << maximal_sum_of_credit << "\n";
  cout << "----------------------------------------------------------\n";
  utility_.Sleep(500);
  utility_.WriteTextWithDelay(
      "\n# Do you prefer get all sum or you want to change the sum of "
      "loan?\n\n"
      "# 1. Get all sum\n"
      "# 2. Change the sum of loan\n"
      "# 3. Main menu\n"
      "# 4. Exit\n");
  cout << "# Enter: ";
}

void UserMessanger::ShowInfoAboutCredit(UserMessanger::string &user_login,
                                        int max_sum) {
  cout << "\t             Consumer credit\n"
          "\t* Profile: "
       << user_login << "\n\t* Sum $: " << max_sum
       << "\n\t* Persent per year: 14%\n\n ";
}

void UserMessanger::ShowEnrollACredit() {
  utility_.WriteTextWithDelay(
      "\n# The loan was successfully transferred on your account.\n"
      "# You might cash your credit in our nearest bank.");
  utility_.IgnoreCinLine();
}

void UserMessanger::ShowIndividualCreditInfo(UserMessanger::string &user_login,
                                             int sum_of_credit) {
  cout << "\t\tConsumer Credit\n\n";
  utility_.Sleep(500);
  cout << "Profile: " << user_login << "\n";
  utility_.Sleep(500);
  cout << "Sum $: " << sum_of_credit << "\n";
  utility_.Sleep(500);
  cout << "Persent per year: 14%\n\n";
  utility_.Sleep(2500);
}

void UserMessanger::ShowRefuseACredit(int sum_of_cash) const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay("# We checked your balance.\n");
  utility_.Sleep(500);
  cout << "# Available cash = $" << sum_of_cash << "\n";
  utility_.WriteTextWithDelay(
      "# Sorry, for getting a loan your balance must be "
      "$1000 or more.\n");
  utility_.Sleep(500);
}

void UserMessanger::RefusToGrantAnotherCredit() const {
  utility_.WriteTextWithDelay(
      "\n #Sorry, but you have already a "
      "loan in our bank.\n"
      " #You can't get a second loan, "
      "while your first loan "
      "not complete.\n");
}

void UserMessanger::SuggestUserToExit() const {
  utility_.WriteTextWithDelay(
      "\n\t# Do you really want to exit?\n"
      "\t# 1. No, go to main\n"
      "\t# 2. Yes, exit\n");
  cout << "\t# Enter: ";
}

void UserMessanger::WishAGoodDay() const {
  cout << "\n\t####################\n"
          "\t#                  #\n"
          "\t# Have a nice day! #\n"
          "\t#                  #\n"
          "\t####################\n\n";
}

void UserMessanger::ShowTransactionMenu() const {
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
