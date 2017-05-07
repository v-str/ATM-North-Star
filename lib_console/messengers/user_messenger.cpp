#include <user_messenger.h>

#include <console_editor.h>

void UserMessenger::ShowMainMenu() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "\n\t################ Transaction menu ##################\n"
      "\t#                                                  #\n"
      "\t# 1. Account information            2. Refill      #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 3. Credit application             4. Withdrawal  #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 5. Statement                      6. Exit        #\n"
      "\t#                                                  #\n"
      "\t####################################################\n"
      "\tEnter: ");
}

void UserMessenger::ReRequestAboutExit() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t# Do you really want to exit?");
}

void UserMessenger::WishAGoodDay() {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::WriteText(
      "\n\t####################\n"
      "\t#                  #\n"
      "\t# Have a nice day! #\n"
      "\t#                  #\n"
      "\t####################\n\n");
}

void UserMessenger::SuggestToExit() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t# 1. Exit to main page.\n"
      "\t# 2. Exit program.\n"
      "\t# Enter: ");
}

void UserMessenger::ShowIncorrectInput() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t# Incorrect input, please try again", 10);
  ConsoleEditor::WriteTextWithDelayPerSymbol("...", 100);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Enter: ");
}

void UserMessenger::ShowIncorrectMainMenuInput() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t# Incorrect input, please try again", 20);
  ConsoleEditor::Sleep(200);
}

void UserMessenger::ShowIncorrectRegisterData() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\tIncorrect input, "
      "\n\treload the program\n");
}
