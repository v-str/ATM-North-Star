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
      "\t##  3. Credit                        4. Withdrawal  ##\n"
      "\t##  ----------------------           -------------  ##\n"
      "\t##  5. Statement                                    ##\n"
      "\t##  ----------------------------------------------  ##\n"
      "\t##  6. Log out                       7. Quit        ##\n"
      "\t##                                                  ##\n"
      "\t######################################################\n"
      "\t######################################################\n"
      "\tEnter: ",
      1);
}

void MainMenuMessenger::LogOutMessage() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t## Logout performed...");
  ConsoleEditor::Sleep(kDelay);
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
