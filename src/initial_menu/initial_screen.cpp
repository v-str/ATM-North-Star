#include "initial_screen.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

void InitialScreen::DisplayInitialScreen() {
  DisplayLogotype();
  DisplayInitialMenu();
}

void InitialScreen::DisplayInitialMenu() const {
  cout << "\n\n\n\n\t ##################\n"
          "\t #  1. Demo mode  #\n"
          "\t #  2. Sign-in    #\n"
          "\t ##################\n"
          "\t   Enter: ___"
       << "\b\b";
}

void InitialScreen::DisplayLogotype()  {
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

  utility_.WriteTextWithDelay(
      "\t    ATM - machine 4528\n"
      "  Adress - 28 Greene St, New York, NY 10012\n");
  utility_.WriteTextWithDelay("\t      Press any key", 50);
  cin.clear();
  EatLine();
  system("pause");
  system("clear");
}

void InitialScreen::DisplayError() const {
  utility_.WriteTextWithDelay(
      "\n\n\tData is not correct,\n"
      "\tplease reload the program.\n\n");
}

void InitialScreen::EatLine() {
  while (std::cin.get() != '\n') continue;
}
