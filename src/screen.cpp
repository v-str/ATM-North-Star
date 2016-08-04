#include "screen.h"

#include <iostream>
#include <string>

#include "system_utility.h"

using std::string;
using std::cout;

void Welcome() {
  cout << "\n\n\n\n\t\t##################\n"
          "\t\t#  1. Demo mode  #\n"
          "\t\t#  2. Sign-in    #\n"
          "\t\t##################\n"
          "\t\t   Enter: ___"
       << "\b\b";
}

static void Write(const string &str, int write_latency = 55) {
  for (const auto &symbol : str) {
    cout << symbol;
    Sleep(write_latency);
  }
}

void MnScreen() {
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
  string description =
      "\t    ATM - machine 4528\n"
      "  Adress - 28 Greene St, New York, NY 10012\n";
  cout << demo;
  Write(description);
  cout << "\t";
  system("pause");
  system("cls");
}

void Error() {
  string err =
      "\n\n\t Data is not correct,"
      "please reload the program.\n\n";
  Write(err);
}
