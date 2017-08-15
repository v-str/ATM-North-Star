#include <initial_messenger.h>

#include <console_editor.h>

void InitialMessenger::DisplaySplashScreen() { DisplayLogotype(); }

void InitialMessenger::DisplayLogotype() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "---------------------------------------------\n"
      "-  ##   ## ####### ######  ######## ##  ##  -\n"
      "-  ###  ## ##   ## ##   ##    ##    ##  ##  -\n"
      "-  ## # ## ##   ## ######     ##    ######  -\n"
      "-  ##  ### ##   ## ##  ##     ##    ##  ##  -\n"
      "-  ##   ## ####### ##   ##    ##    ##  ##  -\n"
      "-                                           -\n"
      "-     ######  ########    #####  ######     -\n"
      "-     ##         ##      ##  ##  ##   ##    -\n"
      "-     ######     ##     ##   ##  ######     -\n"
      "-         ##     ##    ########  ##  ##     -\n"
      "-     ######     ##    ##    ##  ##   ##    -\n"
      "-                                           -\n"
      "-        ######  ########  ###     ###      -\n"
      "-       ##   ##     ##     ####   ####      -\n"
      "-      ##    ##     ##     ## ## ## ##      -\n"
      "-     ## ### ##     ##     ##  ###  ##      -\n"
      "-     ##     ##     ##     ##   #   ##      -\n"
      "---------------------------------------------\n");

  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t         ATM #0001\n"
      "      28 Greene St, New York, NY 10012\n");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t      press \"Enter\"\n");
  ConsoleEditor::IgnoreCinLine();
  ConsoleEditor::ClearScreen();
}

void InitialMessenger::DisplayInitialMenu() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "\n\n\n\n\t ###############################\n"
      "\t #                             #\n"
      "\t #  1. Login                   #\n"
      "\t #  2. Registration            #\n"
      "\t #  3. Demo                    #\n"
      "\t #                             #\n"
      "\t #  (press 'q' for quit)       #\n"
      "\t #                             #\n"
      "\t ###############################\n"
      "\t   Enter: ");
}
void InitialMessenger::ShowIncorrectMenuInput() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t Incorrect input, please repeat: ", 15);
}

void InitialMessenger::FarewellMessage() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\tThank you for using ATM North Star.\n"
      "\tHave a nice day!\n\n");
}
