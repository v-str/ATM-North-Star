#include <user_messenger.h>

#include <console_editor_duplicate.h>

void UserMessenger::ShowMainMenu() {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteText(
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

void UserMessenger::ReRequestAboutExit() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\t# Do you really want to exit?");
}

void UserMessenger::WishAGoodDay() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(2);
  ConsoleEditorDuplicate::WriteText(
      "\n\t####################\n"
      "\t#                  #\n"
      "\t# Have a nice day! #\n"
      "\t#                  #\n"
      "\t####################\n\n");
}

void UserMessenger::ShowMainMenu() const {
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteText(
      "\n\t################ Transaction menu ##################\n"
      "\t#                                                  #\n"
      "\t# 1. Account information            2. Refill      #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 3. Credit application             4. Withdrawal  #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 5. Statement                      6. Exit        #\n"
      "\t#                                                  #\n"
      "\t####################################################\n");
}

void UserMessenger::SuggestToExit() const {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(1);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\t# 1. Exit to main page.\n"
      "\t# 2. Exit program.\n"
      "\t# Enter: ");
}

void UserMessenger::ShowIncorrectInput() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\t# Incorrect input, please try again", 10);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol("...", 100);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol("\n\t# Enter: ");
}

void UserMessenger::ShowIncorrectMainMenuInput() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\t# Incorrect input, please try again", 20);
  ConsoleEditorDuplicate::Sleep(200);
}

void UserMessenger::ShowIncorrectRegisterData() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\n\tIncorrect input, "
      "\n\treload the program\n");
}
