#include "system_utility.h"

#include <chrono>
#include <iostream>
#include <limits>
#include <thread>

using std::cin;
using std::cout;
using std::string;

void Sleep(int latency_ms) {
  std::this_thread::sleep_for(std::chrono::milliseconds(latency_ms));
}

void WriteTextWithDelay(const string &text) {
  for (const auto &symbol : text) {
    cout << symbol;
    cout.flush();
    Sleep(5);
  }
  cout << "\n";
}

void IgnoreCinLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ClearScreen() { system("clear"); }

void ShowDemoMenu()
{
    cout << "\t################ Demo Transaction menu ###################\n"
            "\t#                                                        #\n"
            "\t#  1. Account information            2. Refill           #\n"
            "\t#  ----------------------            ------------        #\n"
            "\t#  3. Credit application             4. Withdrawal       #\n"
            "\t#  ----------------------            ------------        #\n"
            "\t#  5. Statement                      6. Exit             #\n"
            "\t#                                                        #\n"
            "\t#                   7. Create Account                    #\n"
            "\t#                                                        #\n"
            "\t##########################################################\n\n"
            "\t# Enter: ";
}

void ShowWelcomeDemoMessage()
{
    WriteTextWithDelay(
        "# Welcome to demo mode. This chapter\n"
        "# contains basic information about ATM North Star.\n\n"
        "# First of all, look at the main menu:\n");

    WriteTextWithDelay("# Please, choose interested you chapter:\n");
}
