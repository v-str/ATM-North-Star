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
