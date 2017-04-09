#ifndef CONSOLE_EDITOR_H
#define CONSOLE_EDITOR_H

#include <sstream>
#include <string>

#include "text_writer.h"

class ConsoleEditor {
 public:
  void ClearScreen() const;

  void Sleep(int latency_ms = 15) const;
  void IgnoreCinLine() const;
  void WriteTextWithDelayPerSymbol(const std::string& text,
                                   int delay = 5) const;
  void WriteSymbolsNTimes(const std::string& symbol, int n) const;
  void AddEmptyLineNTimes(int amount_of_empty_lines) const;
  void WriteText(const std::string& text) const;
  void WriteTextWithInterrupt(const std::string& text, int interrupt) const;
  void WriteTextInFrame(const std::string& text,
                        const std::string& frame_symbol) const;

  template <typename T>
  std::string ConvertValueToString(const T& value) const;
};

template <typename T>
std::string ConsoleEditor::ConvertValueToString(const T& value) const {
  std::stringstream stream;
  stream << value;
  return stream.str();
}

#endif  // CONSOLE_EDITOR_H
