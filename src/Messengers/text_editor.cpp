#include "text_editor.h"

#include <chrono>
#include <iostream>
#include <thread>

void TextEditor::Sleep(int latency_ms) const {
  std::this_thread::sleep_for(std::chrono::milliseconds(latency_ms));
}

void TextEditor::IgnoreCinLine() const {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void TextEditor::ClearScreen() const { system("clear"); }

void TextEditor::WriteTextWithDelay(const string &text, int delay) const {
  for (const auto &symbol : text) {
    std::cout << symbol;
    Sleep(delay);
  }
}

void TextEditor::WriteSymbolsNTimes(char symbol, int n) const {
  for (int i = 0; i < n; ++i) {
    std::cout << symbol;
  }
}
