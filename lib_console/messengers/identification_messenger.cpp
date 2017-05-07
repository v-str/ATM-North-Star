#include <identification_messenger.h>

#include <console_editor.h>

void IdentificationMessenger::ShowInitialLoginText() const {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\n\n\tLogin: ", kDelay);
}

void IdentificationMessenger::ShowInitialPasswordText() const {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\tPassword: ", kDelay);
}
