#ifndef CONSOLE_EDITOR_H
#define CONSOLE_EDITOR_H

#include <string>

class ConsoleEditor {
  using string = std::string;

 public:
  void Sleep(int latency_ms) const;
  void IgnoreCinLine() const;
  void ClearScreen() const;
  void WriteTextWithDelay(const string &text, int delay = 15) const;
  void WriteSymbolsNTimes(char symbol, int n) const;
};

#endif  // CONSOLE_EDITOR_H
