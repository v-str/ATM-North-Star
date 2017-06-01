#include <authentication_messenger.h>

#include <console_editor.h>

void AuthenticationMessenger::DisplayLoginText() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\n\n\tLogin: ", kDelay);
}

void AuthenticationMessenger::DisplayPasswordText() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\tPassword: ", kDelay);
}
