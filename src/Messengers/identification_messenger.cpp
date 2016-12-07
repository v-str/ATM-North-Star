#include "identification_messenger.h"

void IdentificationMessenger::ShowInitialLoginText() const {
  console_editor_.WriteTextWithDelayPerSymbol("\n\n\n\tLogin: ", kDelay);
  console_editor_.WriteSymbolsNTimes("#", kMaxLenghtOfLogin);
  console_editor_.WriteSymbolsNTimes("\b", kMaxLenghtOfLogin);
}

void IdentificationMessenger::ShowInitialPasswordText() const {
  console_editor_.WriteTextWithDelayPerSymbol("\n\tPassword: ", kDelay);
  console_editor_.WriteSymbolsNTimes("X", kMaxLenghtOfPassword);
  console_editor_.WriteSymbolsNTimes("\b", kMaxLenghtOfPassword);
}
