#ifndef CONSOLE_EDITOR_H
#define CONSOLE_EDITOR_H

#include <string>

class ConsoleEditor {
  using string = std::string;

 public:
  static void ClearScreen();

  void Sleep(int latency_ms = 15) const;
  void IgnoreCinLine() const;
  void WriteTextWithDelay(const string &text, int delay = 15) const;
  void WriteSymbolsNTimes(char symbol, int n) const;

  void WriteText(const string &text) const;
  void WriteTextWithInterrupt(const string &text, const int interrupt) const;
};

#endif  // CONSOLE_EDITOR_H
