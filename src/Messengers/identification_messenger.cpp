#include "identification_messenger.h"

void IdentificationMessenger::ShowInitialLoginText() const {
  console_editor_.WriteTextWithDelayPerSymbol("\n\n\n\t\tLogin: ", kDelay);
  console_editor_.WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  console_editor_.WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
}

void IdentificationMessenger::ShowInitialPasswordText() const {
  console_editor_.WriteTextWithDelayPerSymbol("\n\t\tPassword: XXXX\b\b\b\b",
                                              kDelay);
  console_editor_.WriteSymbolsNTimes('X', kMaxLenghtOfPassword);
  console_editor_.WriteSymbolsNTimes('\b', kMaxLenghtOfPassword);
}
