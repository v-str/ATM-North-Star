#include <identification_messenger.h>

#include <console_editor_duplicate.h>

void IdentificationMessenger::ShowInitialLoginText() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol("\n\n\n\tLogin: ",
                                                      kDelay);
}

void IdentificationMessenger::ShowInitialPasswordText() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol("\n\tPassword: ", kDelay);
}
