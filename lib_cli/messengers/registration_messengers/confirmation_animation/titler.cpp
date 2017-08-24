#include <titler.h>

#include <console_editor.h>

void Titler::WriteTitle(const std::string title_string) {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteText("      ");
  ConsoleEditor::WriteText(title_string);
  ConsoleEditor::AddEmptyLineNTimes(2);
}
