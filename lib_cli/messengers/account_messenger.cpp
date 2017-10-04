#include <account_messenger.h>

#include <console_editor.h>
#include <text_writer.h>

int AccountMessenger::kStripLength = 20;

void AccountMessenger::DisplayInfoLine(const std::string& info_title,
                                       const std::string& info_line) {
  ConsoleEditor::WriteText("\n" + info_title + info_line + "\n");
  DisplayStrip();
}

void AccountMessenger::SetStripLength(int strip_length) {
  kStripLength = strip_length;
}

int AccountMessenger::StripLength() { return kStripLength; }

void AccountMessenger::DisplayStrip() {
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::Sleep(kSleep);
}
