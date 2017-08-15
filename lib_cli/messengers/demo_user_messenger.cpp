#include <demo_user_messenger.h>

#include <console_editor.h>

void DemoUserMessenger::ShowMessage(
    DemoUserMessenger::MessageType message_type) {
  ConsoleEditor::AddEmptyLineNTimes(2);

  switch (message_type) {
    case kWelcome:
      ShowWelcomeDemoMessage();
      break;
    case kAccountInfo:
      ShowDemoAccountInfoMessage();
      break;
    case kRefillInfo:
      ShowInfoAboutRefillMessage();
      break;
    case kCreditInfo:
      ShowDemoCreditAppMessage();
      break;
    case kWithdrawalInfo:
      ShowDemoWidthdrawalMessage();
      break;
    case kStatementInfo:
      ShowDemoStatementMessage();
      break;
  }
}

void DemoUserMessenger::ShowWelcomeDemoMessage() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "# Welcome to demo mode. This chapter\n"
      "# contains basic information about ATM North Star.\n"
      "# First of all, look at the main menu:\n"
      "# Please, choose interested menu:\n");
}

void DemoUserMessenger::ShowDemoMenu(DisplayMode display_mode) {
  switch (display_mode) {
    case kCLearScreen:
      ConsoleEditor::ClearScreen();
      break;
    case kNoClearScreen:
      break;
    default:
      break;
  }

  ConsoleEditor::WriteText(
      "\n\n\t################# Demo Transaction menu ################\n"
      "\t#                                                      #\n"
      "\t#   1. Account information           2. Refill         #\n"
      "\t#  ------------------------          ---------------   #\n"
      "\t#   3. Credit application            4. Withdrawal     #\n"
      "\t#  ------------------------          ---------------   #\n"
      "\t#   5. Statement                                       #\n"
      "\t#                                                      #\n"
      "\t#  -------------------------------------------------   #\n"
      "\t#                                                      #\n"
      "\t#   8. Exit to initial menu          9. Exit program   #\n"
      "\t#                                                      #\n"
      "\t########################################################\n\n"
      "\n\t# Enter interested menu: ");
}

void DemoUserMessenger::ShowDemoAccountInfoMessage() {
  ConsoleEditor::AddEmptyLineNTimes(3);
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "# This section show your account information.\n"
      "# For example, it's look like this:\n\n");
  ConsoleEditor::WriteTextWithInterrupt(
      "--------------------------------------------\n# Login: Mr. Anderson\n",
      kSleep);
  ConsoleEditor::WriteTextWithInterrupt("# Password: Correct\n", kSleep);
  ConsoleEditor::WriteTextWithInterrupt("# Credit $: 20000\n", kSleep);
  ConsoleEditor::WriteTextWithInterrupt("# Monthly payment $: 2280\n", kSleep);
  ConsoleEditor::WriteTextWithInterrupt(
      "# Credit term: 20 "
      "month(s)\n--------------------------------------------\n\n",
      kSleep);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "# As you can see, your account may contain different data like\n"
      "# balance or credit balance, almost you can see more details such as\n"
      "# how many month you must to pay a loan  etc.\n\n");
}

void DemoUserMessenger::ShowInfoAboutRefillMessage() {
  ConsoleEditor::AddEmptyLineNTimes(3);
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithInterrupt(
      "# In this section user may refill balance\n"
      "# on any sum from 10 to 50000 dollars.\n"
      "# You can enter any sum such as 100 or 1005.66.\n"
      "# When you refill on 1005.66  supposed, that you making a\n"
      "# transfer from another account.\n\n"
      "# For example, refill account is look like this:\n",
      kSleep);
  ConsoleEditor::WriteText(
      "-----------------------------------------------\n"
      " Entered sum: 1700 $\n"
      "-----------------------------------------------\n"
      " (If sum is valid, money will be transferred)\n\n");
}

void DemoUserMessenger::ShowDemoCreditAppMessage() {
  ConsoleEditor::AddEmptyLineNTimes(3);
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "# Our bank may allow you to get a loan in the amount\n"
      "# of not more than 15x of your cash on account at the\n"
      "# moment.\n\n"
      "# For example: \n"
      "# If your balance at the moment equal $2000, you may\n"
      "# get a $30000 loan on individual conditions.\n\n");
}

void DemoUserMessenger::ShowDemoWidthdrawalMessage() {
  ConsoleEditor::AddEmptyLineNTimes(3);
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "# Withdrawal happens to your existing account.\n"
      "# Optionally, you can withdraw the entire amount at\n"
      "# once or choose the amount that you need to be.\n");
}

void DemoUserMessenger::ShowDemoStatementMessage() {
  ConsoleEditor::AddEmptyLineNTimes(3);
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "# Standart statement which contain information\n"
      "# about your cash.\n");
}

void DemoUserMessenger::ShowIncorrectInput() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t# Incorrect input, please try again:\n"
      "\t# Enter: ");
}

void DemoUserMessenger::ShowIncorrectMenuInput() {
  ConsoleEditor::ClearScreen();
  ShowIncorrectInput();
}

void DemoUserMessenger::SuggestExit() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# 1. Return to demo menu\n"
      "\t# 2. Exit program\n"
      "\t# Enter: ");
}
