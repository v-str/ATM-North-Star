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

void ConsoleEditor::ClearScreen() const {
  int system_status = system("clear");

  if (system_status == -1) {
    WriteSymbolsNTimes("\n", 50);
  }
}

void ConsoleEditor::WriteTextWithDelayPerSymbol(const std::string& text,
                                                int delay) const {
  for (const auto symbol : text) {
    std::string temp(1, symbol);

    TextWriter::Write(temp);

    Sleep(delay);
  }
}

void ConsoleEditor::WriteSymbolsNTimes(std::string symbol, int n) const {
  for (int i = 0; i < n; ++i) {
    TextWriter::Write(symbol);
  }
}

void ConsoleEditor::AddEmptyLineNTimes(int amount_of_empty_lines) const {
  for (int i = 0; i < amount_of_empty_lines; ++i) {
    TextWriter::Write("\n");
  }
}

void ConsoleEditor::WriteText(const std::string& text) const {
  TextWriter::Write(text);
}

void ConsoleEditor::WriteTextWithInterrupt(const std::string& text,
                                           int interrupt) const {
  WriteTextWithDelayPerSymbol(text);
  Sleep(interrupt);
}
