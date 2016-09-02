#include "system_utility.h"

#include <chrono>
#include <iostream>
#include <limits>
#include <thread>

using std::cin;
using std::cout;
using std::string;

void SystemUtility::Sleep(int latency_ms) const {
  std::this_thread::sleep_for(std::chrono::milliseconds(latency_ms));
}

void SystemUtility::IgnoreCinLine() const {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void SystemUtility::ClearScreen() const { system("clear"); }

void SystemUtility::WriteTextWithDelay(const string &text, int delay) const {
  for (const auto &symbol : text) {
    cout << symbol;
    cout.flush();
    Sleep(delay);
  }
  cout << "\n";
}
