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

void InitialMessenger::DisplayInitialMenu() const {
  cout << "\n\n\n\n\t ##################\n"
          "\t #  1. Demo mode  #\n"
          "\t #  2. Sign-in    #\n"
          "\t ##################\n"
          "\t   Enter: ___"
       << "\b\b";
}

void InitialMessenger::DisplayLogotype()  {
  string demo =
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
      "---------------------------------------------\n";
  cout << demo;

  text_editor_.WriteTextWithDelay(
      "\t         ATM #0001\n"
      "  Adress - 28 Greene St, New York, NY 10012\n");
  text_editor_.WriteTextWithDelay("\t      press \"Enter\"", 50);
  cin.clear();
  EatLine();
  system("pause");
  system("clear");
}

void InitialMessenger::DisplayError() const {
  text_editor_.WriteTextWithDelay(
      "\n\n\tData is not correct,\n"
      "\tplease reload the program.\n\n");
}

void InitialMessenger::EatLine() {
  while (std::cin.get() != '\n') continue;
}
