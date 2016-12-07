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

void ConsoleEditor::Pause() { system("pause"); }

void ConsoleEditor::ClearScreen() { system("clear"); }

void ConsoleEditor::WriteTextWithDelayPerSymbol(const string &text,
                                                int delay) const {
  for (const auto symbol : text) {
    std::string temp(1, symbol);

    TextWriter::Write(temp);

    Sleep(delay);
  }
}

void ConsoleEditor::WriteSymbolsNTimes(char symbol, int n) const {
  for (int i = 0; i < n; ++i) {
    std::string temp(1, symbol);

    TextWriter::Write(temp);
  }
}

void ConsoleEditor::WriteText(const ConsoleEditor::string &text) const {
  TextWriter::Write(text);
}

void ConsoleEditor::WriteTextWithInterrupt(const ConsoleEditor::string &text,
                                           const int interrupt) const {
  WriteTextWithDelayPerSymbol(text);
  Sleep(interrupt);
}
