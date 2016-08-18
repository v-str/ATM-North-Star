#include "demo_user.h"
#include "user.h"

#include <iostream>
#include <string>

#include "system_utility.h"

using std::cin;
using std::cout;
using std::string;

static void WriteTextWithDelay(const string &text) {
  for (const auto &symbol : text) {
    cout << symbol;
    cout.flush();
    Sleep(5);
  }
  cout << "\n";
}

void DemoUser::ShowDemoMenu() const {
  cout << "\t############Demo Transaction menu ########################\n"
          "\t#                                                        #\n"
          "\t# 1. Account information            2. Refill            #\n"
          "\t# ----------------------            ------------         #\n"
          "\t# 3. Credit application             4. Withdrawal        #\n"
          "\t# ----------------------            ------------         #\n"
          "\t# 5. Statement                      6. Create account    #\n"
          "\t#                                                        #\n"
          "\t##########################################################\n\n"
          "\t# Enter: ";
}

void DemoUser::ShowWelcomeMessage() const {
  WriteTextWithDelay(
      "# Welcome to demo mode. This chapter\n"
      "# contains basic information about ATM North Star.\n\n"
      "# First of all, look at the main menu: \n\n");

  WriteTextWithDelay("# Please, choose interested you chapter: ");
}

void DemoUser::ShowDemoMode() {
  ClearScreen();
  ShowWelcomeMessage();
  for (;;) {
    ShowDemoMenu();
    if (UserDecideToExit()) {
      // ShowExitMessage();
      break;
    }
    ClearScreen();
  }
}

bool DemoUser::UserDecideToExit() {
  int choice = GetValueFromUser();
  if (choice == 1) {
    return DemoAccountInfo();
  } else if (choice == 2) {
    return DemoRefill();
  } else if (choice == 3) {
    return DemoCreditApp();
  } else if (choice == 4) {
    return DemoWidthdrawal();
  } else if (choice == 5) {
    return DemoStatement();
  } else if (choice == 6) {
    return StartRegistration();
  } else {
    return ShowIncorrectMessage();
  }
}

bool DemoUser::StartRegistration() {
  AtmUser user;
  user.Registration();
  return true;
}

void DemoUser::ClearScreen() const { system("clear"); }

bool DemoUser::DemoAccountInfo() const {
  ClearScreen();
  string AccInfo =
      "# This section show your account information.\n"
      "# For example, it's look like this:\n";
  WriteTextWithDelay(AccInfo);
  cout << "--------------------------------------------\n";
  cout << "# Login: Mr. Anderson\n";
  cout << "--------------------------------------------\n";
  Sleep(100);
  cout << "# Password: 7623\n";
  cout << "--------------------------------------------\n";
  Sleep(100);
  cout << "# Balance $: 7450\n";
  cout << "--------------------------------------------\n";
  Sleep(100);
  cout << "# Credit $: 20000\n";
  cout << "# Monthly payment $: 2280\n";
  cout << "# Credit term: 20 month(s)\n";
  cout << "--------------------------------------------\n\n";
  Sleep(100);

  WriteTextWithDelay(
      "# As you can see, your account may contain different data like\n"
      "# balance or credit balance, almost you can see more details such as\n"
      "# how many month you must to pay a loan  etc.\n\n");
  if (SuggestUserToExit()) {
    ShowExitMessage();
  }
  return SuggestUserToExit();
}

bool DemoUser::SuggestUserToExit() const {
  WriteTextWithDelay(
      "# 1. Exit to start demo page.\n"
      "# 2. Exit program.\n");
  cout << "Enter: ";
  int user_want_to_exit = GetValueFromUser();

  return user_want_to_exit == 2;
}

int DemoUser::GetValueFromUser() const {
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

void DemoUser::ShowExitMessage() const {
  string exit =
      "\n# Thank you for using our ATM system,\n"
      "# have a nice day!\n\n";
  WriteTextWithDelay(exit);
}

bool DemoUser::DemoRefill() const {
  ClearScreen();
  string demoref =
      "# In this section user may refill balance\n"
      "# on any sum from 10 to 50000 dollars.\n"
      "# You can enter any sum such as 100 or 1005.66.\n"
      "# When you refill on 1005.66  supposed, that you making a\n"
      "# transfer from another account.\n\n"
      "# For example, refill account is look like this:";
  WriteTextWithDelay(demoref);
  cout << "------------------------------------------\n"
          " Entered sum: 1000 $\n"
          "------------------------------------------\n"
          " If sum a valid, money will be tranferred.\n"
          "------------------------------------------\n\n";
  return SuggestUserToExit();
}

bool DemoUser::DemoCreditApp() const {
  ClearScreen();

  string credit_app =
      "# Our bank may allow you to get a loan on the amount\n"
      "# of not more than 15x of your cash on account at the "
      "moment.\n\n";
  WriteTextWithDelay(credit_app);

  return SuggestUserToExit();
}

bool DemoUser::DemoWidthdrawal() const {
  ClearScreen();

  string widthdrawal =
      "# Withdrawal happens to your existing account.\n"
      "# Optionally, you can withdraw the entire amount at\n"
      "# once or choose the amount that you need to be.\n";
  WriteTextWithDelay(widthdrawal);

  return SuggestUserToExit();
}

bool DemoUser::DemoStatement() const {
  ClearScreen();

  string state =
      "# Standart statement which contain information\n"
      "# about your cash.\n";
  WriteTextWithDelay(state);

  return SuggestUserToExit();
}

bool DemoUser::ShowIncorrectMessage() const {
  string err = "\t Data is not correct, please reload the program.\n\n";
  WriteTextWithDelay(err);
  return true;
}
