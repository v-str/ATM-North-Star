#include "messanger.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;

void Messanger::ShowDemoMenu() const {
  cout << "\t################ Demo Transaction menu ###################\n"
          "\t#                                                        #\n"
          "\t#  1. Account information            2. Refill           #\n"
          "\t#  ----------------------            ------------        #\n"
          "\t#  3. Credit application             4. Withdrawal       #\n"
          "\t#  ----------------------            ------------        #\n"
          "\t#  5. Statement                      6. Exit             #\n"
          "\t#                                                        #\n"
          "\t#                   7. Create Account                    #\n"
          "\t#                                                        #\n"
          "\t##########################################################\n\n"
          "\t# Enter: ";
}

void Messanger::ShowWelcomeDemoMessage() const {
  WriteTextWithDelay(
      "# Welcome to demo mode. This chapter\n"
      "# contains basic information about ATM North Star.\n\n"
      "# First of all, look at the main menu:\n");

  WriteTextWithDelay("# Please, choose interested you chapter:\n");
}

void Messanger::ShowDemoAccountInfoMsg() const {
  WriteTextWithDelay(
      "# This section show your account information.\n"
      "# For example, it's look like this:\n");
  cout << "--------------------------------------------\n";
  cout << "# Login: Mr. Anderson\n";
  Sleep(100);
  cout << "# Password: 7623\n";
  Sleep(100);
  cout << "# Balance $: 7450\n";
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
}

void Messanger::ShowInfoAboutRefillMsg() const {
  WriteTextWithDelay(
      "# In this section user may refill balance\n"
      "# on any sum from 10 to 50000 dollars.\n"
      "# You can enter any sum such as 100 or 1005.66.\n"
      "# When you refill on 1005.66  supposed, that you making a\n"
      "# transfer from another account.\n\n"
      "# For example, refill account is look like this:");
  cout << "-----------------------------------------------\n"
          " Entered sum: 1000 $\n"
          "-----------------------------------------------\n"
          " (If sum is valid, money will be transferred)\n\n";
}

void Messanger::ShowDemoCreditAppMsg() const {
  ClearScreen();
  WriteTextWithDelay(
      "# Our bank may allow you to get a loan on the amount\n"
      "# of not more than 15x of your cash on account at the "
      "# moment.\n\n"
      "# For example: \n"
      "# If your balance at the moment equal $2000, you may\n"
      "# get a $30000 loan on individual conditions.\n\n");
}

void Messanger::ShowDemoWidthdrawalMsg() const {
  ClearScreen();
  WriteTextWithDelay(
      "# Withdrawal happens to your existing account.\n"
      "# Optionally, you can withdraw the entire amount at\n"
      "# once or choose the amount that you need to be.\n");
}

void Messanger::ShowDemoStatementMsg() const {
  ClearScreen();
  WriteTextWithDelay(
      "# Standart statement which contain information\n"
      "# about your cash.\n");
}
