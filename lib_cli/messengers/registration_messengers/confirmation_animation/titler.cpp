#include <titler.h>

#include <console_editor.h>

Titler::Titler(const std::string& title_string) : title_string_(title_string) {}

void Titler::WriteTitle() const {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteText("      ");
  ConsoleEditor::WriteText(title_string_);
  ConsoleEditor::AddEmptyLineNTimes(2);
}
