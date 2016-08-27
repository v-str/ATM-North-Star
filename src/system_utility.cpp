#include "system_utility.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <limits>

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

void IgnoreNewLineSymbol()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
