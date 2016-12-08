#include "identification_messenger.h"

void IdentificationMessenger::ShowInitialLoginText() const {
  console_editor_.WriteTextWithDelayPerSymbol("\n\n\n\tLogin: ", kDelay);
}

void IdentificationMessenger::ShowInitialPasswordText() const {
  console_editor_.WriteTextWithDelayPerSymbol("\n\tPassword: ", kDelay);
}
