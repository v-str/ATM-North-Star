#ifndef SYSTEM_UTILITY_H
#define SYSTEM_UTILITY_H

#include <string>
#include <iostream>

using std::cin;
using std::cout;

class SystemUtility {
  using string = std::string;

 public:
  void CleanFlow() const;
  void Sleep(int latency_ms) const;
  void IgnoreCinLine() const;
  void ClearScreen() const;
  void WriteTextWithDelay(const string &text, int delay = 5) const;
  void WriteSymbolsNTimes(char symbol, int n) const;
};

#endif  // SYSTEM_UTILITY_H
