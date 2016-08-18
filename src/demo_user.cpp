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
    if (RunDemoModeUntilUserWantToExit()) {
      ShowExitMessage();
      break;
    }
    ClearScreen();
  }
}

bool DemoUser::RunDemoModeUntilUserWantToExit() {
  int ch = 0;
  cin >> ch;
  if (ch == 1) {
    return DemoAccInfo();
  } else if (ch == 2) {
    return DemoRefill();
  }  // else if (ch == 3) {
  //    DemoCreditApp();
  //  } else if (ch == 4) {
  //    DemoWidthdrawal();
  //  } else if (ch == 5) {
  //    DemoStatement();
  //  } else if (ch == 6) {
  //    AtmUser user;
  //    user.Registration();
  //  } else {
  //    ShowIncorrectDataMessage();
  //}
}

void DemoUser::ClearScreen() const { system("clear"); }

bool DemoUser::DemoAccInfo() const {
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
  return SuggestUserToExit();
}

bool DemoUser::SuggestUserToExit() const {
  int user_want_to_exit = GetValueFromUser();

  return user_want_to_exit == 2;
}

int DemoUser::GetValueFromUser() const {
  WriteTextWithDelay(
      "# 1. Exit to start demo page.\n"
      "# 2. Exit program.\n");
  cout << "Enter: ";
  int value = 0;
  while (!(cin >> value)) {
    cin.clear();
    while (cin.get() != '\n')
      ;
    cout << "\tIncorrect data. Please, repeat.\n";
    cout << "\t-------------------------------\n";
    cout << "# Enter: _ "
         << "\b\b";
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

void DemoUser::DemoCreditApp() const {
  ClearScreen();

  string credit_app =
      "# Our bank may allow you to get a loan in the amount\n"
      "# of not more than 15 of your account size at the moment.\n\n";
  WriteTextWithDelay(credit_app);

  SuggestUserToExit();
}

void DemoUser::DemoWidthdrawal() const {
  ClearScreen();

  string widthdrawal =
      "# Withdrawal happens to your existing account.\n"
      "# Optionally, you can withdraw the entire amount at\n"
      "# once or choose the amount that you need to be.\n";
  WriteTextWithDelay(widthdrawal);

  SuggestUserToExit();
}

void DemoUser::DemoStatement() const {
  ClearScreen();

  string state =
      "# Standart statement which contain information\n"
      "# about your cash.\n";
  WriteTextWithDelay(state);

  SuggestUserToExit();
}

void DemoUser::ShowIncorrectDataMessage() const {
  string err = "\t Data is not correct, please reload the program.\n\n";
  WriteTextWithDelay(err);
}
