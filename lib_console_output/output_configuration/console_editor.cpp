#include "console_editor.h"

#include <chrono>
#include <iostream>
#include <thread>

void ConsoleEditor::Sleep(int latency_ms) {
  std::this_thread::sleep_for(std::chrono::milliseconds(latency_ms));
}

void ConsoleEditor::IgnoreCinLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleEditor::Pause() { system("pause"); }

void ConsoleEditor::ClearScreen() { system("clear"); }

void ConsoleEditor::WriteTextWithDelayPerSymbol(const string &text, int delay) {
  for (const auto symbol : text) {
    std::string temp(1, symbol);

    TextWriter::Write(temp);

    Sleep(delay);
  }
}

void ConsoleEditor::WriteSymbolsNTimes(std::string symbol, int n) {
  for (int i = 0; i < n; ++i) {
    TextWriter::Write(symbol);
  }
}

void ConsoleEditor::AddEmptyLineNTimes(int amount_of_empty_lines) {
  for (int i = 0; i < amount_of_empty_lines; ++i) {
    TextWriter::Write("\n");
  }
}

void ConsoleEditor::WriteText(const ConsoleEditor::string &text) {
  TextWriter::Write(text);
}

void ConsoleEditor::WriteTextWithInterrupt(const ConsoleEditor::string &text,
                                           int interrupt) {
  WriteTextWithDelayPerSymbol(text);
  Sleep(interrupt);
}
