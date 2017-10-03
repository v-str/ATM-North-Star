#include <console_login_menu.h>

#include <console_editor.h>

ConsoleLoginMenu::ConsoleLoginMenu() {}

void ConsoleLoginMenu::RunLoginMenu() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "Login menu is under construction...\n\n"
      "Press \"Enter\" to continue...");
  ConsoleEditor::IgnoreCinLine();
}
