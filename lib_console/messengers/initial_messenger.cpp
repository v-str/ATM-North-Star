#include <initial_messenger.h>

#include <console_editor.h>

void InitialMessenger::DisplayInitialScreen() {
  DisplayLogotype();
  DisplayInitialMenu();
}

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
  ConsoleEditor::WriteText(
      "\n\n\n\n\t ###############################\n"
      "\t #                             #\n"
      "\t #  1. Demo                    #\n"
      "\t #  2. Registration            #\n"
      "\t #  3. Log-in (not available)  #\n"
      "\t #                             #\n"
      "\t #  (press 'q' for quit)       #\n"
      "\t #                             #\n"
      "\t ###############################\n"
      "\t   Enter: ");
}
