#include <console_editor_duplicate.h>
#include <identification_messenger.h>

void IdentificationMessenger::ShowInitialLoginText() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol("\n\n\n\tLogin: ",
                                                      kDelay);
}

void IdentificationMessenger::ShowInitialPasswordText() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol("\n\tPassword: ", kDelay);
}
