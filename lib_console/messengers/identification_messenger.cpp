#include <identification_messenger.h>

#include <console_editor.h>

void IdentificationMessenger::ShowInitialLoginText() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\n\n\tLogin: ", kDelay);
}

void IdentificationMessenger::ShowInitialPasswordText() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\tPassword: ", kDelay);
}
