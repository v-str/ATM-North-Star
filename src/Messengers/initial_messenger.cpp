#include "initial_messenger.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

void InitialMessenger::DisplayInitialScreen() {
  DisplayLogotype();
  DisplayInitialMenu();
}

void InitialMessenger::DisplayLogotype() {
  console_editor_.WriteText(
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

  console_editor_.WriteTextWithDelayPerSymbol(
      "\t         ATM #0001\n"
      "      28 Greene St, New York, NY 10012\n");
  console_editor_.WriteTextWithDelayPerSymbol("\t      press \"Enter\"\n", 50);
  console_editor_.IgnoreCinLine();
  system("pause");
  console_editor_.ClearScreen();
}

void InitialMessenger::DisplayInitialMenu() const {
  cout << "\n\n\n\n\t ##################\n"
          "\t #  1. Demo mode  #\n"
          "\t #  2. Sign-in    #\n"
          "\t ##################\n"
          "\t   Enter: ___"
       << "\b\b";
}

void InitialMessenger::DisplayError() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n\n\tData is not correct,\n"
      "\tplease reload the program.\n\n");
}
