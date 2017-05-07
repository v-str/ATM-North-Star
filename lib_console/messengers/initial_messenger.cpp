#include <console_editor_duplicate.h>
#include <initial_messenger.h>

void InitialMessenger::DisplayInitialScreen() {
  DisplayLogotype();
  DisplayInitialMenu();
}

void InitialMessenger::DisplayLogotype() {
  ConsoleEditorDuplicate::WriteText(
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

  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\t         ATM #0001\n"
      "      28 Greene St, New York, NY 10012\n");
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\t      press \"Enter\"\n");
  ConsoleEditorDuplicate::IgnoreCinLine();
  ConsoleEditorDuplicate::ClearScreen();
}

void InitialMessenger::DisplayInitialMenu() const {
  ConsoleEditorDuplicate::WriteText(
      "\n\n\n\n\t #######################\n"
      "\t #  1. Demo mode       #\n"
      "\t #  2. Registration    #\n"
      "\t #######################\n"
      "\t   Enter: ");
}
