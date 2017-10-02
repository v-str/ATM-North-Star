#include <main_menu_messenger.h>

#include <console_editor.h>

void MainMenuMessenger::ShowMainMenu() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::WriteText(
      "\t######################################\n"
      "\t##                   ATM North Star ##\n"
      "\t##                                  ##\n"
      "\t##          Operation menu          ##\n"
      "\t##                                  ##\n"
      "\t##      1. Account information      ##\n"
      "\t##     ------------------------     ##\n"
      "\t##      2. Refill                   ##\n"
      "\t##     ------------------------     ##\n"
      "\t##      3. Withdrawal               ##\n"
      "\t##     ------------------------     ##\n"
      "\t##      4. Credit Calculator        ##\n"
      "\t##     ------------------------     ##\n"
      "\t##                                  ##\n"
      "\t##                                  ##\n"
      "\t##     ------------------------     ##\n"
      "\t##      5. Log out    6. Quit       ##\n"
      "\t##     ------------------------     ##\n"
      "\t##                                  ##\n"
      "\t######################################\n\n"
      "\tEnter: ");
}

void MainMenuMessenger::LogOutMessage() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t## Logout performed...");
  ConsoleEditor::Sleep(kDelay);
}

void MainMenuMessenger::ShowQuitMenu() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t# 1. Exit to main menu.\n"
      "\t# 2. Exit program.\n"
      "\t# Enter: ");
}

void MainMenuMessenger::ShowIncorrectMenuInput() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t# Incorrect input, please try again", 10);
  ConsoleEditor::WriteTextWithDelayPerSymbol("...", 70);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Enter: ");
}

void MainMenuMessenger::PressEnterToContinue() {
  ConsoleEditor::WriteText("\n\t## Press \"Enter\" to continue...");
  ConsoleEditor::IgnoreCinLine();
}
