#include <application_messenger.h>

#include <console_editor.h>

void ApplicationMessenger::ShowIncorrectMenuInput() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "Incorrect input, please try again", 10);
  ConsoleEditor::WriteTextWithDelayPerSymbol("...", 70);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\nEnter: ");
}

void ApplicationMessenger::PressEnterToContinue() {
  ConsoleEditor::WriteText(
      "\nPress \"Enter\"\n"
      "to continue...");
  ConsoleEditor::IgnoreCinLine();
}
