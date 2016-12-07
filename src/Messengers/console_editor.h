#ifndef CONSOLE_EDITOR_H
#define CONSOLE_EDITOR_H

#include "text_writer.h"

#include <sstream>
#include <string>

class ConsoleEditor {
  using string = std::string;

 public:
  static void ClearScreen();

  void Sleep(int latency_ms = 15) const;
  void IgnoreCinLine() const;
  void Pause();
  void WriteTextWithDelayPerSymbol(const string &text, int delay = 5) const;
  void WriteSymbolsNTimes(char symbol, int n) const;

  void WriteText(const string &text) const;
  void WriteTextWithInterrupt(const string &text, const int interrupt) const;

  template <typename T>
  std::string ConvertValueToString(const T &value) const;
};

template <typename T>
std::string ConsoleEditor::ConvertValueToString(const T &value) const{
  std::stringstream stream;
  stream << value;
  return stream.str();
}

#endif  // CONSOLE_EDITOR_H
