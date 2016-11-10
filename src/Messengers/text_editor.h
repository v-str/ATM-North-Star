#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <string>

class TextEditor {
  using string = std::string;

 public:
  void Sleep(int latency_ms) const;
  void IgnoreCinLine() const;
  void ClearScreen() const;
  void WriteTextWithDelay(const string &text, int delay = 5) const;
  void WriteSymbolsNTimes(char symbol, int n) const;
};

#endif  // TEXT_EDITOR_H
