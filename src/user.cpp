#include "user.h"

#include <iostream>
#include <limits>

#include "system_utility.h"

using std::cin;
using std::cout;

const int minimal_sum_for_credit = 1000;

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

void AtmUser::Registration() {
  user_messanger_.ShowRegistrationScreen();
  getline(cin, login_);
  cin.sync();
  if (!IsNormalLogin()) {
    user_messanger_.ShowIncorrectLoginMessage();
  } else {
    GetPassword();
    if (!IsNormalPass()) {
      user_messanger_.ShowIncorrectPasswordMessage();
    } else {
      NoticeAboutSuccessfulRegistration();
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
  user_messanger_.ShowTransactionMenu();
  return HandleUserChoice(user_input_.GetChoiceFromUser());
}

bool AtmUser::HandleUserChoice(int choice) {
  utility_.ClearScreen();

  if (choice == kAccountSection) {
    return ShowAccountInfo();
  } else if (choice == kRefillSection) {
    return Refill();
  } else if (choice == kCreditSection) {
    return CreditApplication();
  } else if (choice == kWidthdrawalSection) {
    return Withdrawal();
  } else if (choice == kStatementSection) {
    return Statement();
  } else if (choice == kExitSection) {
    return SuggestUserToExitWithConfirmationMenu();
  } else {
    return user_input_.ShowIncorrectMessage();
  }
}

bool AtmUser::ShowAccountInfo() {
  cout << "\t";
  user_messanger_.WriteSymbolsNTimes('-', 30);

  user_messanger_.WriteUserInfo("Login", login_);
  user_messanger_.WriteUserInfo("Password", password_);
  user_messanger_.WriteUserInfo("Balance", std::to_string(cash_));
  user_messanger_.WriteUserInfo("Credit", std::to_string(credit_));
  user_messanger_.WriteUserInfo("Monthly payment $",
                                std::to_string(monthly_payment_));
  user_messanger_.WriteUserInfo("Credit term",
                                std::to_string(amount_of_credit_month_));

  return user_input_.SuggestUserToExit();
}

bool AtmUser::Refill() {
  cout << "\n\t---------------------------------------\n";
  utility_.WriteTextWithDelay(
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$");
  cout << "\t---------------------------------------\n";
  cout << "\t# Please enter the sum of money($): ";

  int money = 0;
  cin >> money;
  if (money >= 10 && money <= 50000) {
    cash_ += money;
    cout << "\t----------------------------------------\n";
    utility_.WriteTextWithDelay("\t# Balance refill completed successfully.\n");
    cout << "\t# Balance: $" << cash_ << "\n";
    cout << "\t----------------------------------------\n\n";
    cin.sync();
    utility_.Sleep(1000);
  } else {
    cout << "\n\tIncorrect sum, Reconnect to repeat.\n"
            "\t\t - Press any key - \n\n";
  }
  utility_.IgnoreCinLine();
  return user_input_.SuggestUserToExit();
}

bool AtmUser::CreditApplication() {
  if (AlreadyHasACredit()) {
    return RefuseToReCredit();
  } else {
    return ConsiderACredit();  // -
  }
}

bool AtmUser::Withdrawal() {
  cout << "\n\t# Please, enter the required sum: ";

  double maximum_credit_sum = 0.0;
  cin >> maximum_credit_sum;

  if (IsNormalWithdrawal(maximum_credit_sum)) {
    cout << "\t#Sum($): " << maximum_credit_sum << "\n";
    cout << "\t# Please enter your password: XXXX\b\b\b\b";
    string check_pass;
    cin >> check_pass;
    if (check_pass == password_) {
      cash_ -= maximum_credit_sum;
      string success = "\n\t# Withdrawal completed successfully\n";
      utility_.WriteTextWithDelay(success);
      cout << "\t# Sum($): " << maximum_credit_sum << "\n";
      cout << "\t# Balance($): " << cash_ << "\n\n";

    } else {
      string incorrect_pass = "\n\t# Sorry, entered password is incorrect.\n";
      utility_.ClearScreen();
      utility_.WriteTextWithDelay(incorrect_pass);
    }
  } else {
    utility_.WriteTextWithDelay("\n\t# Sorry, but entered sum is incorrect.\n");
  }
  utility_.IgnoreCinLine();
  return user_input_.SuggestUserToExit();
}

bool AtmUser::Statement() {
  utility_.ClearScreen();

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

  return user_input_.SuggestUserToExit();
}

std::string AtmUser::GetSpaces(int cash) const {
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

void AtmUser::ShowIncorrectDataMessage() {
  string err = "\t Data is not correct, please reload the program.\n\n";
  utility_.WriteTextWithDelay(err);
  cin.get();
}

void AtmUser::MonthToRepay() {
  cin >> amount_of_credit_month_;
  if (amount_of_credit_month_ <= 0 || amount_of_credit_month_ > 61) {
    cout << "Number of credit month can't be more than 60\n";
    cout << "The number of months to repay the loan: ";
    MonthToRepay();
  }
}

bool AtmUser::ConsiderACredit() {
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

  if (user_input_.GetChoiceFromUser() == 1) {
    return ConsiderACreditBasedOnCash();
  }
  return false;
}

bool AtmUser::ConsiderACreditBasedOnCash() {
  if (cash_ >= minimal_sum_for_credit) {
    return GiveACredit();
  } else {
    return RefuseACredit();
  }
}

bool AtmUser::GiveACredit() {
  utility_.ClearScreen();
  string GetLoan =
      "# Your balance more than 1000$. You can afford to take the\n"
      "# credit in our bank. The maximum amount for you is:";
  utility_.WriteTextWithDelay(GetLoan);
  double maximal_sum_of_credit = 15 * cash_;
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
  int choice = user_input_.GetChoiceFromUser();

  if (choice == 1) {
    return MaxCreditCalculation(maximal_sum_of_credit);
  } else if (choice == 2) {
    return IndividualCreditCalculation();
  } else if (choice == 3) {
    return false;
  } else if (choice == 4) {
    return ExitCreditMenu();
  } else {
    return ReloadProgram();
  }
}

bool AtmUser::MaxCreditCalculation(double max_sum) {
  cout << "\nThe number of months to repay the loan: ";
  MonthToRepay();

  utility_.ClearScreen();

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

    utility_.Sleep(50);
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
    return EnrollACredit(max_sum, pay_per_month);
  } else if (choice == 2) {
    return RepealACredit();
  } else if (choice == 3) {
    return ExitCreditMenu();
  } else {
    return ReloadProgram();
  }
}

bool AtmUser::EnrollACredit(double max_sum, double pay_per_month) {
  credit_ = max_sum;
  monthly_payment_ = pay_per_month;
  utility_.WriteTextWithDelay(
      "\n# The loan was successfully transferred on your account.\n"
      "# You might cash your credit in our nearest bank.");
  utility_.IgnoreCinLine();
  return user_input_.SuggestUserToExit();
}

bool AtmUser::RepealACredit() {
  amount_of_credit_month_ = 0;
  utility_.WriteTextWithDelay("\n\t# Credit is repealed...\n");
  utility_.IgnoreCinLine();
  return user_input_.SuggestUserToExit();
}

bool AtmUser::IndividualCreditCalculation() {
  utility_.ClearScreen();

  string ind = "Individual calculating...\n\n";
  utility_.WriteTextWithDelay(ind);
  double sum_of_credit = 0.0;
  do {
    string error =
        "The entered amount should not "
        "exceed the allowed credit.\n"
        "Enter the appropriate amount: ";
    utility_.WriteTextWithDelay(error);
    cout << "Enter: ";
    cin >> sum_of_credit;
  } while (sum_of_credit >= (15 * cash_));
  cout << "\nThe number of months to repay the loan: ";
  MonthToRepay();

  cout << "\t\tConsumer Credit\n\n";
  utility_.Sleep(500);
  cout << "Profile: " << login_ << "\n";
  utility_.Sleep(500);
  cout << "Sum $: " << sum_of_credit << "\n";
  utility_.Sleep(500);
  cout << "Persent per year: 14%\n\n";
  utility_.Sleep(2500);

  double x = (sum_of_credit * 14) / 100;
  double pay_per_month = (sum_of_credit / amount_of_credit_month_) + (x / 12);

  double all_payment = 0.0;

  for (int i = 0; i < amount_of_credit_month_; ++i) {
    cout << "\t Payment month: " << i + 1
         << "   | Payment sum: " << pay_per_month << " $\n";

    utility_.Sleep(50);
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
    return EnrollACredit(sum_of_credit, pay_per_month);
  } else if (choice == 2) {
    return false;
  } else if (choice == 3) {
    return ExitCreditMenu();
  } else {
    return ReloadProgram();
  }
}

bool AtmUser::ExitCreditMenu() {
  user_input_.ShowExitMessage();
  return true;
}

bool AtmUser::ReloadProgram() {
  ShowIncorrectDataMessage();
  return true;
}

bool AtmUser::RefuseACredit() {
  utility_.ClearScreen();

  utility_.WriteTextWithDelay("# We checked your balance.\n");
  utility_.Sleep(500);
  cout << "# Available cash = $" << cash_ << "\n";

  utility_.WriteTextWithDelay(
      "# Sorry, for getting a loan your balance must be "
      "$1000 or more.\n");
  utility_.Sleep(500);

  return user_input_.SuggestUserToExit();
}

void AtmUser::SetupProgram() { utility_.ClearScreen(); }

bool AtmUser::RefuseToReCredit() {
  utility_.WriteTextWithDelay(
      "\n #Sorry, but you have already a "
      "loan in our bank.\n"
      " #You can't get a second loan, "
      "while your first loan "
      "not complete.\n");
  return ShowAccountInfo();
}

bool AtmUser::SuggestUserToExitWithConfirmationMenu() {
  cout << "\n\t# Do you really want to exit?\n"
          "\t# 1. No, go to main\n"
          "\t# 2. Yes, exit\n";

  cout << "\t# Enter: ";

  return user_input_.GetResultFromUserAboutExit();
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

int AtmUser::GetUserChoiceWithMenuText(const string &menu_text,
                                       const string &choice_text) const {
  utility_.WriteTextWithDelay(menu_text);
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
    utility_.Sleep(5);
  }
  cout << "\n";
}

void AtmUser::NoticeAboutSuccessfulRegistration() {
  utility_.IgnoreCinLine();
  utility_.ClearScreen();
  cout << "\n\n\t\t------------------\n";
  string correct = "\t\t| Access allowed |";
  utility_.WriteTextWithDelay(correct);
  cout << "\t\t------------------\n";
  utility_.Sleep(1000);
  credit_ = 0.0;
  monthly_payment_ = 0.0;
  amount_of_credit_month_ = 0;
}

void AtmUser::GetPassword() {
  cout << "\t\tPassword: XXXX\b\b\b\b";
  cin >> password_;
  cin.sync();
}
