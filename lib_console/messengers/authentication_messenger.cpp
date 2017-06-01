#include <authentication_messenger.h>

#include <console_editor.h>

void AuthenticationMessenger::DisplayLoginText() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\n\n\tLogin: ", kDelay);
}

void AuthenticationMessenger::DisplayPasswordText() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\tPassword: ", kDelay);
}

void AuthenticationMessenger::ShortLogin() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n  Sorry, your login is shorter than required,\n"
      "it must be from 6 to 35 latin alphabet symbols inclusively.");
}
