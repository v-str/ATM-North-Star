#include <authentication_messenger.h>

#include <string>

#include <console_editor.h>

void AuthenticationMessenger::DisplayLoginText() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\n\n\tLogin: ", kDelay);
}

void AuthenticationMessenger::DisplayPasswordText() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\tPassword: ", kDelay);
}

void AuthenticationMessenger::LoginLength(StringLength string_length) {
  std::string length_status = "";

  switch (string_length) {
    case kShortLoginLength:
      length_status = "shorter";
      break;
    case kLongLoginLength:
      length_status = "longer";
    default:
      break;
  }

  WriteLoginTitleStatus();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "  Your login is " + length_status +
      " than required,\n"
      "  it must be from 6 to 35 latin alphabet symbols and \n"
      "  arabic digits inclusively.");
}

void AuthenticationMessenger::LoginContainSpecialSymbol() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "  Your login contain special symbols like a % $ ^ # and so on.\n"
      "  You need to remove this symbols and then try again.");
}

void AuthenticationMessenger::LoginBeginWithSpace() {
  WriteLoginTitleStatus();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      " Your login is starts with space symbol.\n"
      " Please remove unnecessary spaces and try again.");
}

void AuthenticationMessenger::WriteLoginTitleStatus() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n Login status: \n"
      "---------------------\n");
}
