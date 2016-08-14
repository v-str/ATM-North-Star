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

void DemoUser::DemoMode() const {
  ClearScreen();

  string demo =
      "# Welcome to demo mode. This chapter\n"
      "# contains basic information about ATM North Star.\n\n"
      "# First of all, look at the main menu: \n\n";
  WriteTextWithDelay(demo);
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
  WriteTextWithDelay(choose);
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
        AtmUser user;
        user.Registration();
        break;
    }
  }
}

void DemoUser::ClearScreen() const { system("clear"); }

void DemoUser::ShowIncorrectDataMessage() const {
  string err = "\t Data is not correct, please reload the program.\n\n";
  WriteTextWithDelay(err);
}

void DemoUser::DemoAccInfo() const {
  ClearScreen();
  string AccInfo =
      "# This section show your account information.\n"
      "# For example, it's look like this:\n\n";
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
  cout << "--------------------------------------------\n\n\n";
  Sleep(100);

  string Details =
      "# As you can see, you account may contain different data like\n"
      "# balance or credit balance, almost you can see more details such as\n"
      "# how many month you must to pay a loan  etc.\n\n";
  WriteTextWithDelay(Details);
  DemoExit();
}

void DemoUser::DemoRefill() const {
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
  DemoExit();
}

void DemoUser::DemoExit() const {
  string exit =
      "# 1. Exit to start demo page.\n"
      "# 2. Exit program.";
  WriteTextWithDelay(exit);
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

void DemoUser::DemoCreditApp() const {
  ClearScreen();

  string credit_app =
      "# Our bank may allow you to get a loan in the amount\n"
      "# of not more than 15 of your account size at the moment.\n\n";
  WriteTextWithDelay(credit_app);

  DemoExit();
}

void DemoUser::DemoWidthdrawal() const {
  ClearScreen();

  string widthdrawal =
      "# Withdrawal happens to your existing account.\n"
      "# Optionally, you can withdraw the entire amount at\n"
      "# once or choose the amount that you need to be.\n";
  WriteTextWithDelay(widthdrawal);

  DemoExit();
}

void DemoUser::DemoStatement() const {
  ClearScreen();

  string state =
      "# Standart statement which contain information\n"
      "# about your cash.\n";
  WriteTextWithDelay(state);

  DemoExit();
}

void DemoUser::ShowExitMessage() const {
  string exit =
      "\n\tThank you for using our payment system,\n"
      "\thave a nice day!";
  WriteTextWithDelay(exit);
}
