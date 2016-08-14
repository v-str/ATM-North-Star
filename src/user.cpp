#include "user.h"

#include <iostream>

#include "system_utility.h"

using std::cin;
using std::cout;

AtmUser::AtmUser() = default;

AtmUser::AtmUser(const string &login, const string &password, double cash,
                 long credit, double monthly_payment,
                 int amount_of_credit_month)
    : login_(login),
      password_(password),
      cash_(cash),
      credit_(credit),
      monthly_payment_(monthly_payment),
      amount_of_credit_month_(amount_of_credit_month) {}

bool AtmUser::IsNormalLogin() const {
  return !login_.empty() && login_.length() < 21;
}

bool AtmUser::IsNormalPass() const { return password_.length() == 4; }

bool AtmUser::AlreadyHasACredit() const { return credit_ > 0; }

bool AtmUser::IsNormalWithdrawal(double cash_sum) const {
  return cash_sum >= 0 && cash_sum <= cash_;
}

void AtmUser::ClearScreen() { system("clear"); }

void AtmUser::Write(const string &s) const {
  for (const auto &symbol : s) {
    cout << symbol;
    cout.flush();
    Sleep(5);
  }
  cout << "\n";
}

void AtmUser::ShowIncorrectDataMessage() {
  string err = "\t Data is not correct, please reload the program.\n\n";
  Write(err);
}

void AtmUser::ShowExitMessage() {
  string exit =
      "\n\tThank you for using our payment system,\n"
      "\thave a nice day!";
  Write(exit);
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
    Write(credit_access);
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
  Write(ind);
  double sum_of_credit = 0.0;
  do {
    string error =
        "The entered amount should not "
        "exceed the allowed credit.\n"
        "Enter the appropriate amount: ";
    Write(error);
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
  string CreditConfirm =
      "\nDo you confirm the loan?\n"
      "1. Yes, I confirm.\n"
      "2. No, go to the main\n"
      "3. Exit program\n";
  Write(CreditConfirm);
  cout << "Enter: ";
  int cr_choice = 0;
  cin >> cr_choice;
  if (cr_choice == 1) {
    credit_ = sum_of_credit;
    monthly_payment_ = pay_per_month;
    string credit_access =
        "The loan was successfully transferred on your "
        "account.\nYou might cash your credit in our "
        "nearest bank.";
    Write(credit_access);
    return SuggestUserToExitWithDefaultMenu();
  } else if (cr_choice == 2) {
    return false;
  } else if (cr_choice == 3) {
    ShowExitMessage();
    return true;
  } else {
    ShowIncorrectDataMessage();
    return true;
  }
}

void AtmUser::Registration() {
  ClearScreen();

  cout << "\n\t\t   ********************\n"
          "\t\t   *   REGISTRATION   *\n"
          "\t\t   ********************\n";

  cout << "\n\n\n\t\tLogin: "
          "####################\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
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
    Write(incorrect);
    cout << "\t\t\t|---------------------------|\n\n";
  } else {
    cout << "\t\tPassword: XXXX\b\b\b\b";
    cin >> password_;
    cin.sync();
    if (!IsNormalPass()) {
      ClearScreen();
      string incorrect =
          "\t\t|Incorrect password.        |\n"
          "\t\t|It must be in XXXX format. |\n"
          "\t\t|Please, reload the program.|";
      cout << "\n\n\n\n\t\t\t|---------------------------|\n";
      Write(incorrect);
      cout << "\t\t|---------------------------|\n\n\t\t\t";
    } else {
      ClearScreen();
      cout << "\n\n\t\t------------------\n";
      string correct = "\t\t| Access allowed |";
      Write(correct);
      cout << "\t\t------------------\n";
      Sleep(1000);
      credit_ = 0.0;
      monthly_payment_ = 0.0;
      amount_of_credit_month_ = 0;
      RunProgramUntilUserWantToExit();
    }
  }
}

bool AtmUser::ShowAccInfo() {
  cout << "--------------------------------------------\n";
  cout << "# Login: " << login_ << "\n";
  cout << "--------------------------------------------\n";
  Sleep(100);
  cout << "# Password: " << password_ << "\n";
  cout << "--------------------------------------------\n";
  Sleep(100);
  cout << "# Balance $: " << cash_ << "\n";
  cout << "--------------------------------------------\n";
  Sleep(100);
  cout << "# Credit $: " << credit_ << "\n";
  cout << "# Monthly payment $: " << monthly_payment_ << "\n";
  cout << "# Credit term: " << amount_of_credit_month_ << " month(s)\n";
  cout << "--------------------------------------------\n";
  Sleep(100);

  return SuggestUserToExitWithDefaultMenu();
}

bool AtmUser::Refill() {
  string sum =
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$";
  cout << "\n\t---------------------------------------\n";
  Write(sum);
  cout << "\t---------------------------------------\n";
  cout << "\t# Please enter the sum of money($): ";
  int money = 0;
  cin >> money;
  if (money >= 10 && money <= 50000) {
    cash_ += money;
    cout << "\t----------------------------------------\n";
    string success = "\t# Balance refill completed successfully.\n";
    Write(success);
    cout << "\t# Balance: $" << cash_ << "\n";
    cout << "\t----------------------------------------\n\n";
    cin.sync();
    Sleep(1000);
  } else {
    cout << "\n\tIncorrect sum, Reconnect to repeat.\n";
  }
  return SuggestUserToExitWithDefaultMenu();
}

bool AtmUser::ConsiderACredit() {
  ClearScreen();

  ShowCreditInformMessage();

  int choice = GetUserContinueTextChoice();
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
  Write(GetLoan);
  double maximum = 15 * cash_;
  Sleep(500);
  cout << "----------------------------------------------------------\n";
  cout << " \t\t\t $" << maximum << "\n";
  cout << "----------------------------------------------------------\n";
  Sleep(500);
  string Prefer =
      "\n# Do you prefer get all sum or you want to change the sum of "
      "loan?\n";
  Write(Prefer);
  string menu_text =
      "# 1. Get all sum\n"
      "# 2. Change the sum of loan\n"
      "# 3. Main menu\n"
      "# 4. Exit\n"
      "# Enter: ";
  int choice = GetUserChoice(menu_text);

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
  Write(cash_less);
  Sleep(500);
  cout << "# Available cash = $" << cash_ << "\n";
  string entry_more =
      "# Sorry, for getting a loan your balance must be "
      "1000$ or more.\n";
  Write(entry_more);
  Sleep(500);
}

int AtmUser::GetUserContinueTextChoice() {
  string continue_text =
      "\n\t*********************\n"
      "\t*   Continue?       *\n"
      "\t*                   *\n"
      "\t*   1. Yes          *\n"
      "\t*   2. No           *\n"
      "\t*                   *\n"
      "\t*********************\n"
      "\t# Enter: ";
  int choice = GetUserChoice(continue_text);

  return choice;
}

void AtmUser::ShowCreditInformMessage() {
  string reference =
      "# You can get a loan in our bank if your\n"
      "  balance more than $1000.\n"
      "# We draw your attention to the fact that\n"
      "  our bank may refuse you in getting a loan\n"
      "  without giving any reason.\n"
      "# Nowadays, the all loans are set on 14% per year\n"
      "# The loan depend from sum on account at the moment.\n";
  Write(reference);
}

bool AtmUser::Withdrawal() {
  cout << "\n\t# Please, enter the required sum: ";
  double mcs = 0.0;
  cin >> mcs;

  if (IsNormalWithdrawal(mcs)) {
    cout << "\t#Sum($): " << mcs << "\n";
    cout << "\t# Please enter your password: XXXX\b\b\b\b";
    string checkpass;
    cin >> checkpass;
    if (checkpass == password_) {
      cash_ -= mcs;
      string success = "\n\t# Withdrawal completed successfully\n";
      Write(success);
      cout << "\t# Sum($): " << mcs << "\n";
      cout << "\t# Balance($): " << cash_ << "\n";
    } else {
      string incorrect_pass = "\n\t# Sorry, entered password is incorrect.\n";
      ClearScreen();
      Write(incorrect_pass);
    }
  } else {
    ClearScreen();

    string big_sum = "\n\t# Sorry, but entered sum is incorrect.\n";
    Write(big_sum);
  }
  return SuggestUserToExitWithDefaultMenu();
}

bool AtmUser::Statement() {
  ClearScreen();

  string space;
  if (cash_ >= 0 && cash_ < 10)
    space = "          #\n";
  else if (cash_ >= 10 && cash_ < 100)
    space = "         #\n";
  else if (cash_ >= 100 && cash_ < 1000)
    space = "        #\n";
  else if (cash_ >= 1000 && cash_ < 10000)
    space = "       #\n";
  else if (cash_ >= 10000 && cash_ < 100000)
    space = "      #\n";
  else if (cash_ >= 100000 && cash_ < 1000000)
    space = "     #\n";

  cout << "\t##################\n"
          "\t#                #\n"
          "\t#  28 Green st.  #\n"
          "\t#   New - York   #\n"
          "\t#                #\n"
          "\t#   NORTH BANK   #\n"
          "\t#                #\n"
          "\t# Balance:       #\n"
          "\t#   "
       << "$ " << cash_ << space;
  cout << "\t#                #\n"
          "\t#  HAVE A NICE   #\n"
          "\t#      DAY       #\n"
          "\t#                #\n"
          "\t##################\n";
  return SuggestUserToExitWithDefaultMenu();
}

void AtmUser::DemoMode() {
  ClearScreen();

  string demo =
      "# Welcome to demo mode. This chapter\n"
      "# contains basic information about ATM North Star.\n\n"
      "# First of all, look at the main menu: \n\n";
  Write(demo);
  cout << "\t################ Transaction menu ########################\n"
          "\t#                                                        #\n"
          "\t# 1. Account information            2. Refill            #\n"
          "\t# ----------------------            ------------         #\n"
          "\t# 3. Credit application             4. Withdrawal        #\n"
          "\t# ----------------------            ------------         #\n"
          "\t# 5. Statement                      6. Create account    #\n"
          "\t#                                                        #\n"
          "\t##########################################################\n\n";

  string choose = "# Please, choose interested you chapter: ";
  Write(choose);
  cout << "# Enter: _ "
       << "\b\b";
  int ch = 0;
  cin >> ch;
  if (ch < 1 || ch > 6) {
    ShowIncorrectDataMessage();
  } else {
    switch (ch) {
      case 1:
        DemoAccInfo();
        break;
      case 2:
        DemoRefill();
        break;
      case 3:
        DemoCreditApp();
        break;
      case 4:
        DemoWidthdrawal();
        break;
      case 5:
        DemoStatement();
        break;
      case 6:
        Registration();
        break;
    }
  }
}

void AtmUser::DemoAccInfo() {
  ClearScreen();
  string AccInfo =
      "# In this section show your account information.\n"
      "# For example, it's look like this:\n\n";
  Write(AccInfo);
  cout << "--------------------------------------------\n";
  cout << "# Login: " << login_ << "\n";
  cout << "--------------------------------------------\n";
  Sleep(100);
  cout << "# Password: " << password_ << "\n";
  cout << "--------------------------------------------\n";
  Sleep(100);
  cout << "# Balance $: " << cash_ << "\n";
  cout << "--------------------------------------------\n";
  Sleep(100);
  cout << "# Credit $: " << credit_ << "\n";
  cout << "# Monthly payment $: " << monthly_payment_ << "\n";
  cout << "# Credit term: " << amount_of_credit_month_ << " month(s)\n";
  cout << "--------------------------------------------\n\n\n";
  Sleep(100);

  string Details =
      "# As you can see, you account may contain different data like\n"
      "# balance or credit balance, almost you can see more details such as\n"
      "# how many month you must to pay a loan  etc.\n\n";
  Write(Details);
  DemoExit();
}

void AtmUser::DemoRefill() {
  ClearScreen();
  string demoref =
      "# In this section user may refill balance\n"
      "# on any sum from 10 to 50000 dollars.\n"
      "# You can enter any sum such as 100 or 1005.66.\n"
      "# When you refill on 1005.66  supposed, that you making a\n"
      "# transfer from another account.\n\n"
      "# For example, refill account is look like this:";
  Write(demoref);
  cout << "------------------------------------------\n"
          " Entered sum: 1000 $\n"
          "------------------------------------------\n"
          " If sum a valid, money will be tranferred.\n"
          "------------------------------------------\n\n";
  DemoExit();
}

void AtmUser::DemoCreditApp() {
  ClearScreen();

  string credit_app =
      "# Our bank may allow you to get a loan in the amount\n"
      "# of not more than 15 of your account size at the moment.\n\n";
  Write(credit_app);

  DemoExit();
}

void AtmUser::DemoWidthdrawal() {
  ClearScreen();

  string widthdrawal =
      "# Withdrawal happens to your existing account.\n"
      "# Optionally, you can withdraw the entire amount at\n"
      "# once or choose the amount that you need to be.\n";
  Write(widthdrawal);

  DemoExit();
}

void AtmUser::DemoStatement() {
  ClearScreen();

  string state =
      "# Standart statement which contain information\n"
      "# about your cash.\n";
  Write(state);

  DemoExit();
}

void AtmUser::DemoExit() {
  string exit =
      "# 1. Exit to start demo page.\n"
      "# 2. Exit program.";
  Write(exit);
  cout << "Enter: ";
  int ch = 0;
  cin >> ch;
  if (ch == 1) {
    ClearScreen();
    DemoMode();
  } else if (ch == 2) {
    ShowExitMessage();
  } else {
    ShowIncorrectDataMessage();
  }
}

void AtmUser::RunProgramUntilUserWantToExit() {
  SetupProgram();
  for (;;) {
    if (RunProgram()) break;
  }
}

void AtmUser::SetupProgram() { ClearScreen(); }

bool AtmUser::RunProgram() {
  ClearScreen();
  ShowTransactionMenu();

  return HandleUserChoice(GetUserChoice("\tSelect: "));
}

bool AtmUser::HandleUserChoice(int choice) {
  ClearScreen();

  if (choice == 1) {
    return ShowAccInfo();
  } else if (choice == 2) {
    return Refill();
  } else if (choice == 3) {
    return CreditApplication();
  } else if (choice == 4) {
    return Withdrawal();
  } else if (choice == 5) {
    return Statement();
  } else {
    return SuggestUserToExitWithIncorrectDataMenu();
  }
}

bool AtmUser::CreditApplication() {
  if (AlreadyHasACredit()) {
    return RefuseToReCredit();
  } else {
    return ConsiderACredit();
  }
}

bool AtmUser::RefuseToReCredit() {
  string text =
      "\n #Sorry, but you have already a "
      "loan in our bank.\n"
      " #You can't get a second loan, "
      "while your first loan "
      "not complete.\n";
  Write(text);
  ShowAccInfo();
  return SuggestUserToExitWithDefaultMenu();
}

bool AtmUser::SuggestUserToExitWithDefaultMenu() {
  string menu_text =
      "\n\t# Go to the main?\n"
      "\t# 1. Yes\n"
      "\t# 2. No, exit\n";
  string choice_text = "\t# Enter: ";
  return SuggestUserToExit(menu_text, choice_text);
}

bool AtmUser::SuggestUserToExitWithIncorrectDataMenu() {
  string menu_text =
      "\n  Data is not correct:\n"
      "  1. Main menu\n"
      "  2. Exit(any key)\n";
  string choice_text = " Enter: ";
  return SuggestUserToExit(menu_text, choice_text);
}

bool AtmUser::SuggestUserToExit(const string &menu_text,
                                const string &choice_text) {
  bool user_want_to_exit = IsUserWantToExit(menu_text, choice_text);
  if (user_want_to_exit) {
    WishGoodDay();
  }
  return user_want_to_exit;
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
      "\n\t################ Transaction menu #################\n"
      "\t#                                                  #\n"
      "\t# 1. Account information            2. Refill      #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 3. Credit application             4. Withdrawal  #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 5. Statement                      6. Exit(test)  #\n"
      "\t#                                                  #\n"
      "\t####################################################\n";
  cout << select;
}

bool AtmUser::IsUserWantToExit(const string &menu_text,
                               const string &choice_text) {
  return GetUserChoiceWithMenuText(menu_text, choice_text) == 2;
}

int AtmUser::GetUserChoice(const string &choice_text) const {
  cout << choice_text;
  return GetValueFromUser();
}

int AtmUser::GetValueFromUser() const {
  int value = 0;
  cin >> value;
  return value;
}

int AtmUser::GetUserChoiceWithMenuText(const string &menu_text,
                                       const string &choice_text) const {
  Write(menu_text);
  return GetUserChoice(choice_text);
}
