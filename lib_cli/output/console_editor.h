#ifndef CONSOLE_EDITOR_H
#define CONSOLE_EDITOR_H

#include <sstream>
#include <string>

#include <text_writer.h>

class ConsoleEditor {
 public:
  static void ClearScreen();

  static void Sleep(int latency_ms = 15);
  static void IgnoreCinLine();
  static void WriteTextWithDelayPerSymbol(const std::string& text,
                                          int delay = 5);
  static void WriteSymbolsNTimes(const std::string& symbol, int n);
  static void AddEmptyLineNTimes(int amount_of_empty_lines);
  static void WriteText(const std::string& text);
  static void WriteTextWithInterrupt(const std::string& text, int interrupt);

  template <typename T>
  static std::string ConvertValueToString(const T& value);
};

template <typename T>
std::string ConsoleEditor::ConvertValueToString(const T& value) {
  std::stringstream stream;
  stream << value;
  return stream.str();
}

#endif  // CONSOLE_EDITOR_H
