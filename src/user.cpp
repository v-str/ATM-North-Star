#include "user.h"

#include <iostream>
#include <limits>

#include "system_utility.h"

using std::cin;
using std::cout;

const int kInvalidChoice = 0;
const int kExit = 2;
const int kgo_to_main = 1;

static const int kMaxLenghtOfLogin = 21;

AtmUser::AtmUser(const string &login, const string &password, double cash,
                 long credit, double monthly_payment,
                 int amount_of_credit_month)
    : login_(login),
      password_(password),
      cash_(cash),
      credit_(credit),
      monthly_payment_(monthly_payment),
      amount_of_credit_month_(amount_of_credit_month) {}

void AtmUser::WriteSymbolsNTimes(char symbol, int n) const {
  for (int i = 0; i < n; ++i) {
    cout << symbol;
  }
}

void AtmUser::Registration() {
  ClearScreen();

  cout << "\n\t\t   ********************\n"
          "\t\t   *   REGISTRATION   *\n"
          "\t\t   ********************\n";

  cout << "\n\n\n\t\tLogin: ";

  WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);

  cin.ignore();
  getline(cin, login_);
  cin.sync();
  if (!IsNormalLogin()) {
    ClearScreen();
    string incorrect =
        "\t\t|Incorrect login.           |\n"
        "\t\t|It must be more than 1 and |\n"
        "\t\t|less than 20 symbols.      |\n"
        "\t\t|Please, reload the program.|";
    cout << "\n\n\n\n\t\t|---------------------------|\n";
    WriteTextWithDelay(incorrect);
    cout << "\t\t\t|---------------------------|\n\n";
  } else {
    cout << "\t\tPassword: XXXX\b\b\b\b";
    cin >> password_;
    cin.sync();
    if (!IsNormalPass()) {
      ClearScreen();
      cout << "\n\n\n\n\t\t\t|---------------------------|\n";
      string incorrect =
          "\t\t|Incorrect password.        |\n"
          "\t\t|It must be in XXXX format. |\n"
          "\t\t|Please, reload the program.|";
      WriteTextWithDelay(incorrect);
      cout << "\t\t|---------------------------|\n\n\t\t\t";
    } else {
      ClearScreen();
      cout << "\n\n\t\t------------------\n";
      string correct = "\t\t| Access allowed |";
      WriteTextWithDelay(correct);
      cout << "\t\t------------------\n";
      Sleep(1000);
      credit_ = 0.0;
      monthly_payment_ = 0.0;
      amount_of_credit_month_ = 0;
      RunProgramUntilUserWantToExit();
    }
  }
}

void AtmUser::RunProgramUntilUserWantToExit() {
  SetupProgram();
  for (;;) {
    if (RunProgram()) break;
  }
}

bool AtmUser::RunProgram() {
  ClearScreen();
  ShowTransactionMenu();

  return HandleUserChoice(GetUserChoice("\tSelect: "));
}

bool AtmUser::HandleUserChoice(int choice) {
  ClearScreen();

  if (choice == 1) {
    return ShowAccountInfo();  // +
  } else if (choice == 2) {
    return Refill();  // +
  } else if (choice == 3) {
    return CreditApplication();  // -
  } else if (choice == 4) {
    return Withdrawal();  // +
  } else if (choice == 5) {
    return Statement();  // -
  } else if (choice == 6) {
    return SuggestUserToExitWithConfirmationMenu();  // +
  } else {
    return user_input_.ShowIncorrectMessage();  // ++
  }
}

bool AtmUser::ShowAccountInfo() {
  cout << "\t--------------------------------------------\n";
  cout << "\t# Login: " << login_ << "\n";
  cout << "\t--------------------------------------------\n";
  Sleep(100);
  cout << "\t# Password: " << password_ << "\n";
  cout << "\t--------------------------------------------\n";
  Sleep(100);
  cout << "\t# Balance $: " << cash_ << "\n";
  cout << "\t--------------------------------------------\n";
  Sleep(100);
  cout << "\t# Credit $: " << credit_ << "\n";
  cout << "\t# Monthly payment $: " << monthly_payment_ << "\n";
  cout << "\t# Credit term: " << amount_of_credit_month_ << " month(s)\n";
  cout << "\t--------------------------------------------\n\n\n";
  Sleep(100);
  IgnoreNewLineSymbol();
  return user_input_.SuggestUserToExit();
}

bool AtmUser::Refill() {
  cout << "\n\t---------------------------------------\n";
  string notification =
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$";
  WriteTextWithDelay(notification);
  cout << "\t---------------------------------------\n";
  cout << "\t# Please enter the sum of money($): ";
  IgnoreNewLineSymbol();
  int money = user_input_.GetValueFromUser();
  if (money >= 10 && money <= 50000) {
    cash_ += money;
    cout << "\t----------------------------------------\n";
    string success = "\t# Balance refill completed successfully.\n";
    WriteTextWithDelay(success);
    cout << "\t# Balance: $" << cash_ << "\n";
    cout << "\t----------------------------------------\n\n";
    cin.sync();
    Sleep(1000);
  } else {
    cout << "\n\tIncorrect sum, Reconnect to repeat.\n"
            "\t\t - Press any key - \n\n";
    IgnoreNewLineSymbol();
  }
  return user_input_.SuggestUserToExit();
}

bool AtmUser::CreditApplication() {
  if (AlreadyHasACredit()) {
    return RefuseToReCredit();
  } else {
    return ConsiderACredit();
  }
}

bool AtmUser::Withdrawal() {
  cout << "\n\t# Please, enter the required sum: ";
  IgnoreNewLineSymbol();
  double maximum_credit_sum = user_input_.GetValueFromUser();

  if (IsNormalWithdrawal(maximum_credit_sum)) {
    cout << "\t#Sum($): " << maximum_credit_sum << "\n";
    cout << "\t# Please enter your password: XXXX\b\b\b\b";
    string check_pass;
    cin >> check_pass;
    if (check_pass == password_) {
      cash_ -= maximum_credit_sum;
      string success = "\n\t# Withdrawal completed successfully\n";
      WriteTextWithDelay(success);
      cout << "\t# Sum($): " << maximum_credit_sum << "\n";
      cout << "\t# Balance($): " << cash_ << "\n\n";
      IgnoreNewLineSymbol();
    } else {
      string incorrect_pass = "\n\t# Sorry, entered password is incorrect.\n";
      ClearScreen();
      WriteTextWithDelay(incorrect_pass);
    }
  } else {
    WriteTextWithDelay("\n\t# Sorry, but entered sum is incorrect.\n");
  }
  return user_input_.SuggestUserToExit();
}

bool AtmUser::Statement() {
  ClearScreen();

  cout << "\t##################\n"
          "\t#                #\n"
          "\t#  28 Green st.  #\n"
          "\t#   New - York   #\n"
          "\t#                #\n"
          "\t#   NORTH BANK   #\n"
          "\t#                #\n"
          "\t# Balance:       #\n"
          "\t#  $ "
       << cash_ << GetSpaces(cash_) << "#\n";
  cout << "\t#                #\n"
          "\t#  HAVE A NICE   #\n"
          "\t#      DAY       #\n"
          "\t#                #\n"
          "\t##################\n";
  IgnoreNewLineSymbol();
  return user_input_.SuggestUserToExit();
}

string AtmUser::GetSpaces(int cash) const {
  const int kSizeOfField = 12;
  const char space = ' ';
  return string(kSizeOfField - NumberOfDigits(cash), space);
}

int AtmUser::NumberOfDigits(int value) const {
  int number_of_digits = 0;

  if (value == 0) {
    return number_of_digits = 1;
  } else {
    while (value != 0) {
      ++number_of_digits;
      value /= 10;
    }
  }
  return number_of_digits;
}

bool AtmUser::IsNormalLogin() const {
  return !login_.empty() && login_.length() < kMaxLenghtOfLogin;
}

bool AtmUser::IsNormalPass() const { return password_.length() == 4; }

bool AtmUser::AlreadyHasACredit() const { return credit_ > 0; }

bool AtmUser::IsNormalWithdrawal(double cash_sum) const {
  return cash_sum > 0 && cash_sum <= cash_;
}

void AtmUser::ClearScreen() { system("clear"); }

void AtmUser::ShowIncorrectDataMessage() {
  string err = "\t Data is not correct, please reload the program.\n\n";
  WriteTextWithDelay(err);
}

void AtmUser::ShowExitMessage() {
  string exit =
      "\n\tThank you for using our payment system,\n"
      "\thave a nice day!";
  WriteTextWithDelay(exit);
}

void AtmUser::MonthToRepay() {
  cin >> amount_of_credit_month_;
  if (amount_of_credit_month_ <= 0 || amount_of_credit_month_ > 61) {
    cout << "Number of credit month can't be more than 60\n";
    cout << "The number of months to repay the loan: ";
    MonthToRepay();
  }
}

bool AtmUser::MaxCreditCalculation(double max_sum) {
  cout << "\nThe number of months to repay the loan: ";
  MonthToRepay();

  ClearScreen();

  cout << "\t             Consumer credit\n"
          "\t* Profile: "
       << login_ << "\n"
                    "\t* Sum $: "
       << max_sum << "\n"
                     "\t* Persent per year: 14%\n\n ";

  double x = (max_sum * 14) / 100;
  double pay_per_month = (max_sum / amount_of_credit_month_) + (x / 12);

  double all_payment = 0.0;

  for (int i = 0; i < amount_of_credit_month_; ++i) {
    cout << "\t* Payment month: " << i + 1 << "   | Payment sum: ";
    cout << pay_per_month << " $\n";

    Sleep(50);
    all_payment += pay_per_month;
  }
  cout << "                \t          Total: " << all_payment << " $\n";
  cout << "\n";
  string menu_text =
      "\n\t# Do you confirm the loan?\n"
      "\t1. Yes, I confirm.\n"
      "\t2. No, go to the main.\n"
      "\t3. Exit program.\n";

  int choice = GetUserChoiceWithMenuText(menu_text, "\tEnter: ");

  if (choice == 1) {
    credit_ = max_sum;
    monthly_payment_ = pay_per_month;
    string credit_access =
        "\n# The loan was successfully transferred on your account.\n"
        "# You might cash your credit in our nearest bank.";
    WriteTextWithDelay(credit_access);
    return SuggestUserToExitWithDefaultMenu();
  } else if (choice == 2) {
    amount_of_credit_month_ = 0;
    return false;
  } else if (choice == 3) {
    ShowExitMessage();
    return true;
  } else {
    ShowIncorrectDataMessage();
    return true;
  }
}

bool AtmUser::IndividualCreditCalculation() {
  ClearScreen();

  string ind = "Individual calculating...\n\n";
  WriteTextWithDelay(ind);
  double sum_of_credit = 0.0;
  do {
    string error =
        "The entered amount should not "
        "exceed the allowed credit.\n"
        "Enter the appropriate amount: ";
    WriteTextWithDelay(error);
    cout << "Enter: ";
    cin >> sum_of_credit;
  } while (sum_of_credit >= (15 * cash_));
  cout << "\nThe number of months to repay the loan: ";
  MonthToRepay();

  cout << "\t\tConsumer Credit\n\n";
  Sleep(500);
  cout << "Profile: " << login_ << "\n";
  Sleep(500);
  cout << "Sum $: " << sum_of_credit << "\n";
  Sleep(500);
  cout << "Persent per year: 14%\n\n";
  Sleep(2500);

  double x = (sum_of_credit * 14) / 100;
  double pay_per_month = (sum_of_credit / amount_of_credit_month_) + (x / 12);

  double all_payment = 0.0;

  for (int i = 0; i < amount_of_credit_month_; ++i) {
    cout << "\t Payment month: " << i + 1
         << "   | Payment sum: " << pay_per_month << " $\n";

    Sleep(50);
    all_payment += pay_per_month;
  }
  cout << "                \t          Total: " << all_payment << " $\n";
  cout << "\n";
  string loan_confirmation_menu_text =
      "\nDo you confirm the loan?\n"
      "1. Yes, I confirm.\n"
      "2. No, go to the main\n"
      "3. Exit program\n";

  int choice =
      GetUserChoiceWithMenuText(loan_confirmation_menu_text, "Enter: ");

  if (choice == 1) {
    credit_ = sum_of_credit;
    monthly_payment_ = pay_per_month;
    string credit_access =
        "The loan was successfully transferred on your "
        "account.\nYou might cash your credit in our "
        "nearest bank.";
    WriteTextWithDelay(credit_access);
    return SuggestUserToExitWithDefaultMenu();
  } else if (choice == 2) {
    return false;
  } else if (choice == 3) {
    ShowExitMessage();
    return true;
  } else {
    ShowIncorrectDataMessage();
    return true;
  }
}

bool AtmUser::ConsiderACredit() {
  ClearScreen();

  string reference_menu_text =
      "# You can get a loan in our bank if your\n"
      "  balance more than $1000.\n"
      "# We draw your attention to the fact that\n"
      "  our bank may refuse you in getting a loan\n"
      "  without giving any reason.\n"
      "# Nowadays, the all loans are set on 14% per year\n"
      "# The loan depend from sum on account at the moment.\n";

  string choice_continue_text =
      "\n\t*********************\n"
      "\t*   Continue?       *\n"
      "\t*                   *\n"
      "\t*   1. Yes          *\n"
      "\t*   2. No           *\n"
      "\t*                   *\n"
      "\t*********************\n"
      "\t# Enter: ";

  int choice =
      GetUserChoiceWithMenuText(reference_menu_text, choice_continue_text);
  if (choice == 1) {
    return ConsiderACreditBasedOnCash();
  } else if (choice == 2) {
    return false;
  } else {
    ShowIncorrectDataMessage();
    return true;
  }
}

bool AtmUser::ConsiderACreditBasedOnCash() {
  if (cash_ >= 1000) {
    return GiveACredit();
  } else {
    RefuseACredit();
    return false;
  }
}

bool AtmUser::GiveACredit() {
  ClearScreen();
  string GetLoan =
      "# Your balance more than 1000$. You can afford to take the\n"
      "# credit in our bank. The maximum amount for you is:";
  WriteTextWithDelay(GetLoan);
  double maximum = 15 * cash_;
  Sleep(500);
  cout << "----------------------------------------------------------\n";
  cout << " \t\t\t $" << maximum << "\n";
  cout << "----------------------------------------------------------\n";
  Sleep(500);
  string prefer_menu_text =
      "\n# Do you prefer get all sum or you want to change the sum of "
      "loan?\n\n"
      "# 1. Get all sum\n"
      "# 2. Change the sum of loan\n"
      "# 3. Main menu\n"
      "# 4. Exit\n";

  int choice = GetUserChoiceWithMenuText(prefer_menu_text, "# Enter: ");

  if (choice == 1) {
    return MaxCreditCalculation(maximum);
  } else if (choice == 2) {
    return IndividualCreditCalculation();
  } else if (choice == 3) {
    return false;
  } else if (choice == 4) {
    ShowExitMessage();
    return true;
  } else {
    ShowIncorrectDataMessage();
    return true;
  }
}

void AtmUser::RefuseACredit() {
  ClearScreen();
  string cash_less = "# We checked your balance.\n";
  WriteTextWithDelay(cash_less);
  Sleep(500);
  cout << "# Available cash = $" << cash_ << "\n";
  string entry_more =
      "# Sorry, for getting a loan your balance must be "
      "1000$ or more.\n";
  WriteTextWithDelay(entry_more);
  Sleep(500);
}

void AtmUser::SetupProgram() { ClearScreen(); }

bool AtmUser::RefuseToReCredit() {
  string text =
      "\n #Sorry, but you have already a "
      "loan in our bank.\n"
      " #You can't get a second loan, "
      "while your first loan "
      "not complete.\n";
  WriteTextWithDelay(text);
  ShowAccountInfo();
  return SuggestUserToExitWithDefaultMenu();
}

bool AtmUser::SuggestUserToExitWithDefaultMenu() {
  string default_menu_text =
      "\n\t# Go to the main?\n"
      "\t# 1. Yes\n"
      "\t# 2. No, exit\n";
  string choice_text = "\t# Enter: ";
  return IsUserWantToExit(default_menu_text, choice_text);
}

bool AtmUser::SuggestUserToExitWithIncorrectDataMenu() {
  string incorrect_data_menu_text =
      "\n  Data is not correct:\n"
      "  1. Main menu\n"
      "  2. Exit(any key)\n";
  string choice_text = " Enter: ";
  return IsUserWantToExit(incorrect_data_menu_text, choice_text);
}

bool AtmUser::SuggestUserToExitWithConfirmationMenu() {
  cout << "\n\t# Do you really want to exit?\n"
          "\t# 1. No, go to main\n"
          "\t# 2. Yes, exit\n";

  cout << "\t# Enter: ";
  IgnoreNewLineSymbol();
  return user_input_.GetResultFromUser();
}

void AtmUser::WishGoodDay() {
  cout << "\n\t####################\n"
          "\t#                  #\n"
          "\t# Have a nice day! #\n"
          "\t#                  #\n"
          "\t####################\n\n";
}

void AtmUser::ShowTransactionMenu() {
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

bool AtmUser::IsUserWantToExit(const string &menu_text,
                               const string &choice_text) {
  return GetUserChoiceWithMenuText(menu_text, choice_text) == 2;
}

int AtmUser::GetUserChoiceWithMenuText(const string &menu_text,
                                       const string &choice_text) const {
  WriteTextWithDelay(menu_text);
  return GetUserChoice(choice_text);
}

int AtmUser::GetUserChoice(const string &choice_text) const {
  cout << choice_text;
  return GetChoiceFromUser();
}

int AtmUser::GetChoiceFromUser() const {
  int value = 0;
  while (!(cin >> value)) {
    cin.clear();
    while (cin.get() != '\n')
      ;
    cout << "\tIncorrect data. Please, repeat.\n";
    cout << "\t-------------------------------\n";
    cout << "\tSelect: ";
  }
  return value;
}

void AtmUser::WriteTextWithDelay(const string &text) const {
  for (const auto &symbol : text) {
    cout << symbol;
    cout.flush();
    Sleep(5);
  }
  cout << "\n";
}
