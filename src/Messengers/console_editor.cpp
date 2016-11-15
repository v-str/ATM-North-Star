#include "console_editor.h"

#include <chrono>
#include <iostream>
#include <thread>

void ConsoleEditor::Sleep(int latency_ms) const {
  std::this_thread::sleep_for(std::chrono::milliseconds(latency_ms));
}

void ConsoleEditor::IgnoreCinLine() const {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleEditor::ClearScreen() const { system("clear"); }

void ConsoleEditor::WriteTextWithDelay(const string &text, int delay) const {
  for (unsigned int i = 0; i < text.length(); ++i) {
    std::cout << text[i];
    Sleep(delay);
  }
}

void ConsoleEditor::WriteSymbolsNTimes(char symbol, int n) const {
  for (int i = 0; i < n; ++i) {
    std::cout << symbol;
  }
}
