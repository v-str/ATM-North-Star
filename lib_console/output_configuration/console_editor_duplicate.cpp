#include "console_editor_duplicate.h"
#include "console_editor.h"

#include <chrono>
#include <iostream>
#include <thread>

void ConsoleEditorDuplicate::Sleep(int latency_ms) {
  std::this_thread::sleep_for(std::chrono::milliseconds(latency_ms));
}

void ConsoleEditorDuplicate::IgnoreCinLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleEditorDuplicate::ClearScreen() {
  int system_status = system("clear");
  if (system_status == -1) {
    WriteSymbolsNTimes("\n", 50);
  }
}

void ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
    const std::string& text, int delay) {
  for (const auto symbol : text) {
    std::string temp(1, symbol);

    TextWriter::Write(temp);

    Sleep(delay);
  }
}

void ConsoleEditorDuplicate::WriteSymbolsNTimes(const std::string& symbol,
                                                int n) {
  for (int i = 0; i < n; ++i) {
    TextWriter::Write(symbol);
  }
}

void ConsoleEditorDuplicate::AddEmptyLineNTimes(int amount_of_empty_lines) {
  for (int i = 0; i < amount_of_empty_lines; ++i) {
    TextWriter::Write("\n");
  }
}

void ConsoleEditorDuplicate::WriteText(const std::string& text) {
  TextWriter::Write(text);
}

void ConsoleEditorDuplicate::WriteTextWithInterrupt(const std::string& text,
                                                    int interrupt) {
  WriteTextWithDelayPerSymbol(text);
  Sleep(interrupt);
}
