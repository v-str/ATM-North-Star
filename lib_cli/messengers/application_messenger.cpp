#include <application_messenger.h>

#include <console_editor.h>

void ApplicationMessenger::ShowIncorrectMenuInput() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t# Incorrect input, please try again", 10);
  ConsoleEditor::WriteTextWithDelayPerSymbol("...", 70);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Enter: ");
}

void ApplicationMessenger::PressEnterToContinue() {
  ConsoleEditor::WriteText("\n\t## Press \"Enter\" to continue...");
  ConsoleEditor::IgnoreCinLine();
}
