#include <account_messenger.h>
#include <console_editor_duplicate.h>
#include <text_writer.h>

void AccountMessenger::DisplayInfoLine(const std::string& info_title,
                                       const std::string& info_line) const {
  ConsoleEditorDuplicate::WriteText("\n\t#" + info_title + info_line + "\n\t");
  DisplayStrip();
}

void AccountMessenger::DisplayStrip() const {
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", kNTimes);
  ConsoleEditorDuplicate::Sleep(kSleep);
}
