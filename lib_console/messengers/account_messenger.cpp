#include <account_messenger.h>

#include <console_editor.h>
#include <text_writer.h>

void AccountMessenger::DisplayInfoLine(const std::string& info_title,
                                       const std::string& info_line) const {
  ConsoleEditor::WriteText("\n\t#" + info_title + info_line + "\n\t");
  DisplayStrip();
}

void AccountMessenger::DisplayStrip() const {
  ConsoleEditor::WriteSymbolsNTimes("-", kNTimes);
  ConsoleEditor::Sleep(kSleep);
}
