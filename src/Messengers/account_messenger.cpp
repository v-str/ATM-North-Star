#include "account_messenger.h"
#include "text_writer.h"

#include <iostream>

void AccountMessenger::DisplayInfoLine(const std::string &info_title,
                                       const std::string &info_line) const {
  TextWriter::Write("\n\t#" + info_title + info_line + "\n\t");

  DisplayStrip();
}

void AccountMessenger::DisplayStrip() const {
  console_editor_.WriteSymbolsNTimes("-", kNTimes);
  console_editor_.Sleep(kSleep);
}
