#include <titler.h>

#include <console_editor.h>

std::string Titler::kIndent = "\t    ";

void Titler::WriteLogoTitle(const std::string title_string) {
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteText(kIndent);
  ConsoleEditor::WriteText(title_string);
  ConsoleEditor::AddEmptyLineNTimes(2);
}

void Titler::WriteEnterMessage() {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "   Loading complete, press \"Enter\"", kTextDelay);
  ConsoleEditor::IgnoreCinLine();
}
