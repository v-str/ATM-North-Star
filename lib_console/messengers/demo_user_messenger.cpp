#include <demo_user_messenger.h>

#include <console_editor_duplicate.h>

void DemoMessanger::ShowMessage(DemoMessanger::MessageType message_type) const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(2);

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

void DemoMessanger::ShowWelcomeDemoMessage() const {
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "# Welcome to demo mode. This chapter\n"
      "# contains basic information about ATM North Star.\n\n"
      "# First of all, look at the main menu:\n"
      "# Please, choose interested you chapter:\n");
}

void DemoMessanger::ShowDemoMenu() const {
  ConsoleEditorDuplicate::WriteText(
      "\n\n\t################ Demo Transaction menu ###################\n"
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
      "\n\t# Enter: ");
}

void DemoMessanger::ShowDemoAccountInfoMessage() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(3);
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "# This section show your account information.\n"
      "# For example, it's look like this:\n\n");
  ConsoleEditorDuplicate::WriteTextWithInterrupt(
      "--------------------------------------------\n# Login: Mr. Anderson\n",
      kSleep);
  ConsoleEditorDuplicate::WriteTextWithInterrupt("# Password: 7623\n", kSleep);
  ConsoleEditorDuplicate::WriteTextWithInterrupt("# Credit $: 20000\n", kSleep);
  ConsoleEditorDuplicate::WriteTextWithInterrupt("# Monthly payment $: 2280\n",
                                                 kSleep);
  ConsoleEditorDuplicate::WriteTextWithInterrupt(
      "# Credit term: 20 "
      "month(s)\n--------------------------------------------\n\n",
      kSleep);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "# As you can see, your account may contain different data like\n"
      "# balance or credit balance, almost you can see more details such as\n"
      "# how many month you must to pay a loan  etc.\n\n");
}

void DemoMessanger::ShowInfoAboutRefillMessage() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(3);
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteTextWithInterrupt(
      "# In this section user may refill balance\n"
      "# on any sum from 10 to 50000 dollars.\n"
      "# You can enter any sum such as 100 or 1005.66.\n"
      "# When you refill on 1005.66  supposed, that you making a\n"
      "# transfer from another account.\n\n"
      "# For example, refill account is look like this:\n",
      kSleep);
  ConsoleEditorDuplicate::WriteText(
      "-----------------------------------------------\n"
      " Entered sum: 1700 $\n"
      "-----------------------------------------------\n"
      " (If sum is valid, money will be transferred)\n\n");
}

void DemoMessanger::ShowDemoCreditAppMessage() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(3);
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "# Our bank may allow you to get a loan in the amount\n"
      "# of not more than 15x of your cash on account at the\n"
      "# moment.\n\n"
      "# For example: \n"
      "# If your balance at the moment equal $2000, you may\n"
      "# get a $30000 loan on individual conditions.\n\n");
}

void DemoMessanger::ShowDemoWidthdrawalMessage() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(3);
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "# Withdrawal happens to your existing account.\n"
      "# Optionally, you can withdraw the entire amount at\n"
      "# once or choose the amount that you need to be.\n");
}

void DemoMessanger::ShowDemoStatementMessage() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(3);
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "# Standart statement which contain information\n"
      "# about your cash.\n");
}

void DemoMessanger::ShowDemoMenuAgain() const {
  ConsoleEditorDuplicate::ClearScreen();
  ShowDemoMenu();
}

void DemoMessanger::ShowIncorrectInput() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\t# Incorrect input, please try again:\n"
      "\t# Enter: ");
}

void DemoMessanger::ShowIncorrectMenuInput() const {
  ConsoleEditorDuplicate::ClearScreen();
  ShowIncorrectInput();
}

void DemoMessanger::SuggestExit() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\n\t# 1. Exit to main page.\n"
      "\t# 2. Exit program.\n"
      "\t# Enter: ");
}
