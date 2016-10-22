#include "demo_user_messanger.h"

void DemoUserMessanger::ShowMessage(
    DemoUserMessanger::MessageType message_type) {
  switch (message_type) {
    case kWelcome:
      ShowWelcomeDemoMessage();
      break;
    case kMenu:
      ShowDemoMenu();
      break;
    case kAccountInfo:
      ShowDemoAccountInfoMessage();
      break;
    case kRefill:
      ShowInfoAboutRefillMessage();
      break;
    case kCreditApp:
      ShowDemoCreditAppMessage();
      break;
    case kWithdrawal:
      ShowDemoWidthdrawalMessage();
      break;
    case kStatement:
      ShowDemoStatementMessage();
      break;
  }
}

void DemoUserMessanger::ShowDemoMenu() const {
  std::cout
      << "\t################ Demo Transaction menu ###################\n"
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

void DemoUserMessanger::ShowWelcomeDemoMessage() const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "# Welcome to demo mode. This chapter\n"
      "# contains basic information about ATM North Star.\n\n"
      "# First of all, look at the main menu:\n");

  utility_.WriteTextWithDelay("# Please, choose interested you chapter:\n");
  ShowDemoMenu();
}

void DemoUserMessanger::ShowDemoAccountInfoMessage() const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "# This section show your account information.\n"
      "# For example, it's look like this:\n");
  std::cout << "--------------------------------------------\n";
  std::cout << "# Login: Mr. Anderson\n";
  utility_.Sleep(kSleep);
  std::cout << "# Password: 7623\n";
  utility_.Sleep(kSleep);
  std::cout << "# Balance $: 7450\n";
  utility_.Sleep(kSleep);
  std::cout << "# Credit $: 20000\n";
  std::cout << "# Monthly payment $: 2280\n";
  std::cout << "# Credit term: 20 month(s)\n";
  std::cout << "--------------------------------------------\n\n";
  utility_.Sleep(kSleep);
  utility_.WriteTextWithDelay(
      "# As you can see, your account may contain different data like\n"
      "# balance or credit balance, almost you can see more details such as\n"
      "# how many month you must to pay a loan  etc.\n\n");
}

void DemoUserMessanger::ShowInfoAboutRefillMessage() const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "# In this section user may refill balance\n"
      "# on any sum from 10 to 50000 dollars.\n"
      "# You can enter any sum such as 100 or 1005.66.\n"
      "# When you refill on 1005.66  supposed, that you making a\n"
      "# transfer from another account.\n\n"
      "# For example, refill account is look like this:");
  std::cout << "-----------------------------------------------\n"
               " Entered sum: 1000 $\n"
               "-----------------------------------------------\n"
               " (If sum is valid, money will be transferred)\n\n";
}

void DemoUserMessanger::ShowDemoCreditAppMessage() const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "# Our bank may allow you to get a loan on the amount\n"
      "# of not more than 15x of your cash on account at the "
      "# moment.\n\n"
      "# For example: \n"
      "# If your balance at the moment equal $2000, you may\n"
      "# get a $30000 loan on individual conditions.\n\n");
}

void DemoUserMessanger::ShowDemoWidthdrawalMessage() const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "# Withdrawal happens to your existing account.\n"
      "# Optionally, you can withdraw the entire amount at\n"
      "# once or choose the amount that you need to be.\n");
}

void DemoUserMessanger::ShowDemoStatementMessage() const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "# Standart statement which contain information\n"
      "# about your cash.\n");
}

void DemoUserMessanger::ShowDemoMenuMessage() const {
  utility_.ClearScreen();
  ShowDemoMenu();
}
