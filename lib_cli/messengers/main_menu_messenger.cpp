#include <main_menu_messenger.h>

#include <console_editor.h>

void MainMenuMessenger::ShowMainMenu() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "######################################\n"
      "##                   ATM North Star ##\n"
      "##                                  ##\n"
      "##          Operation menu          ##\n"
      "##                                  ##\n"
      "##      1. Account information      ##\n"
      "##     ------------------------     ##\n"
      "##      2. Refill                   ##\n"
      "##     ------------------------     ##\n"
      "##      3. Withdrawal               ##\n"
      "##     ------------------------     ##\n"
      "##      4. Credit Calculator        ##\n"
      "##     ------------------------     ##\n"
      "##                                  ##\n"
      "##                                  ##\n"
      "##     ------------------------     ##\n"
      "##      5. Log out    6. Quit       ##\n"
      "##     ------------------------     ##\n"
      "##                                  ##\n"
      "######################################\n\n"
      "Enter: ");
}

void MainMenuMessenger::LogOutMessage() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteTextWithDelayPerSymbol("# Logout performed...");
  ConsoleEditor::Sleep(kDelay);
}

void MainMenuMessenger::ShowQuitMenu() {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "# 1. Exit to main menu.\n"
      "# 2. Exit program.\n"
      "# Enter: ");
}
