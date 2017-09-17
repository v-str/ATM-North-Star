#include <console_editor.h>

#include <chrono>
#include <iostream>
#include <thread>

#include <linux_configurator.h>
#include <win_32_configurator.h>

void ConsoleEditor::Sleep(int latency_ms) {
  std::this_thread::sleep_for(std::chrono::milliseconds(latency_ms));
}

void ConsoleEditor::IgnoreCinLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleEditor::ClearScreen() {
#ifdef WIN32
  Win32Configurator::ClearScreen();
#else
  LinuxConfigurator::ClearScreen();
#endif
}

void ConsoleEditor::WriteTextWithDelayPerSymbol(
    const std::string& text, int delay) {
  for (const auto symbol : text) {
    std::string temp(1, symbol);
    TextWriter::Write(temp);
    Sleep(delay);
  }
}

void ConsoleEditor::WriteSymbolsNTimes(const std::string& symbol,
                                                int n) {
  for (int i = 0; i < n; ++i) {
    TextWriter::Write(symbol);
  }
}

void ConsoleEditor::AddEmptyLineNTimes(int amount_of_empty_lines) {
  for (int i = 0; i < amount_of_empty_lines; ++i) {
    TextWriter::Write("\n");
  }
}

void ConsoleEditor::WriteText(const std::string& text) {
  TextWriter::Write(text);
}

void ConsoleEditor::WriteTextWithInterrupt(const std::string& text,
                                                    int interrupt) {
  WriteTextWithDelayPerSymbol(text);
  Sleep(interrupt);
}
