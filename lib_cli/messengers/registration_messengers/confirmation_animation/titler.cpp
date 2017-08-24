#include <titler.h>

#include <console_editor.h>

std::string Titler::kIndent = "\t    ";

void Titler::WriteTitle(const std::string title_string) {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteText(kIndent);
  ConsoleEditor::WriteText(title_string);
  ConsoleEditor::AddEmptyLineNTimes(2);
}
