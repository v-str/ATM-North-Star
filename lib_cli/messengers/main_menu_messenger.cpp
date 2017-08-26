#include <main_menu_messenger.h>

#include <console_editor.h>

void MainMenuMessenger::ShowMainMenu() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::AddEmptyLineNTimes(3);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t#################################### ATM North Star ##\n"
      "\t################### Operation menu ###################\n"
      "\t##                                                  ##\n"
      "\t##  1. Account information           2. Refill      ##\n"
      "\t##  ----------------------           -------------  ##\n"
      "\t##  3. Credit application            4. Withdrawal  ##\n"
      "\t##  ----------------------           -------------  ##\n"
      "\t##  5. Statement                     6. Exit        ##\n"
      "\t##                                                  ##\n"
      "\t######################################################\n"
      "\t######################################################\n"
      "\tEnter: ",
      1);
}

void MainMenuMessenger::ReRequestAboutExit() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t# Do you really want to exit?");
}

void MainMenuMessenger::WishAGoodDay() {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::WriteText(
      "\n\t####################\n"
      "\t#                  #\n"
      "\t# Have a nice day! #\n"
      "\t#                  #\n"
      "\t####################\n\n");
}

void MainMenuMessenger::ShowQuitMenu() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t# 1. Exit to main page.\n"
      "\t# 2. Exit program. ( or press 'q')\n"
      "\t# Enter: ");
}

void MainMenuMessenger::ShowIncorrectInput() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t# Incorrect input, please try again", 10);
  ConsoleEditor::WriteTextWithDelayPerSymbol("...", 70);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Enter: ");
}

void MainMenuMessenger::ShowIncorrectMainMenuInput() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t# Incorrect input, please try again", 20);
  ConsoleEditor::Sleep(200);
}

void MainMenuMessenger::ShowIncorrectRegistration() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Incorrect input, reload program.\n");
}
