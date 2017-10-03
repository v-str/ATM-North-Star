#include <application_messenger.h>

#include <console_editor.h>

void ApplicationMessenger::ShowIncorrectMenuInput() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\tIncorrect input, please try again", 10);
  ConsoleEditor::WriteTextWithDelayPerSymbol("...", 70);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\tEnter: ");
}

void ApplicationMessenger::PressEnterToContinue() {
  ConsoleEditor::WriteText("\n\tPress \"Enter\" to continue...");
  ConsoleEditor::IgnoreCinLine();
}
