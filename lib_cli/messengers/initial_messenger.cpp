#include <initial_messenger.h>

#include <console_editor.h>

void InitialMessenger::DisplaySplashScreen() { DisplayLogotype(); }

void InitialMessenger::DisplayLogotype() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "#################################################\n"
      "#                                               #\n"
      "#    ##   ## ####### ######  ######## ##  ##    #\n"
      "#    ###  ## ##   ## ##   ##    ##    ##  ##    #\n"
      "#    ## # ## ##   ## ######     ##    ######    #\n"
      "#    ##  ### ##   ## ##  ##     ##    ##  ##    #\n"
      "#    ##   ## ####### ##   ##    ##    ##  ##    #\n"
      "#                                               #\n"
      "#       ######  ########    #####  ######       #\n"
      "#       ##         ##      ##  ##  ##   ##      #\n"
      "#       ######     ##     ##   ##  ######       #\n"
      "#           ##     ##    ########  ##  ##       #\n"
      "#       ######     ##    ##    ##  ##   ##      #\n"
      "#                                               #\n"
      "#          ######  ########  ###     ###        #\n"
      "#         ##   ##     ##     ####   ####        #\n"
      "#        ##    ##     ##     ## ## ## ##        #\n"
      "#       ## ### ##     ##     ##  ###  ##        #\n"
      "#       ##     ##     ##     ##   #   ##        #\n"
      "#                                               #\n"
      "#################################################\n");

  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t             ATM #0001\n"
      "          28 Greene St, New York, NY 10012\n");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t          press \"Enter\"\n");
  ConsoleEditor::IgnoreCinLine();
  ConsoleEditor::ClearScreen();
}

void InitialMessenger::DisplayInitialMenu() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "\n\n\n\n"
      "######################################\n"
      "#                     ATM North Star #\n"
      "#                                    #\n"
      "#     1. Login                       #\n"
      "#      2. Registration               #\n"
      "#       3. Description               #\n"
      "#        4. Quit                     #\n"
      "#                                    #\n"
      "######################################\n"
      "Enter: ");
}

void InitialMessenger::FarewellMessage() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\nThank you for using ATM North Star.\n"
      "Have a nice day!\n\n");
}
