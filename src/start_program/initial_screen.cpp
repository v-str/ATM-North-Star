#include "initial_screen.h"

#include <iostream>
#include <string>

#include "system_utility.h"

using std::string;
using std::cout;
using std::cin;

void InitialScreen::InitialMenu() const {
  cout << "\n\n\n\n\t\t##################\n"
          "\t\t#  1. Demo mode  #\n"
          "\t\t#  2. Sign-in    #\n"
          "\t\t##################\n"
          "\t\t   Enter: ___"
       << "\b\b";
}

void InitialScreen::Logotype() const {
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
  cout << "\t";
  cin.get();
  system("pause");
  system("clear");
}

void InitialScreen::Error() const {
  utility_.WriteTextWithDelay(
      "\n\n\t Data is not correct,"
      "please reload the program.\n\n");
}
