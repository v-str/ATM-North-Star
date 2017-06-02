#include <authentication_messenger.h>

#include <string>

#include <console_editor.h>

void AuthenticationMessenger::DisplayLoginText() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\n\n\tLogin: ", kDelay);
}

void AuthenticationMessenger::DisplayPasswordText() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\tPassword: ", kDelay);
}

void AuthenticationMessenger::CorrectMessage() {
  WriteLoginTitleStatus();
  ConsoleEditor::WriteText("\tCorrect");
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

void AuthenticationMessenger::LoginContainIncorrectSpacePosition(
    ContainSpaceSymbol space_symbol)

{
  std::string space_status = "";

  switch (space_symbol) {
    case kBeginWithSpace:
      space_status = "is starts with space symbol.";
      break;
    case kEndWithSpace:
      space_status = "is end with space symbol.";
      break;
    case kAdjecentSpaces:
      space_status = "is contain adjacent spaces.";
      break;
    default:
      break;
  }

  WriteLoginTitleStatus();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      " Your login " + space_status +
      "\n"
      " Please remove unnecessary spaces and try again.");
}

void AuthenticationMessenger::LoginContainOnlyDigits() {
  WriteLoginTitleStatus();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      " Your login contain only digits.\n"
      " Login must contain 1 symbol of latin alphabet at the least.");
}

void AuthenticationMessenger::LoginEmpty() {
  WriteLoginTitleStatus();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      " Your login is empty.\n"
      " Please enter a valid login and try again");
}

void AuthenticationMessenger::WriteLoginTitleStatus() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n Login status: \n"
      "---------------------\n");
}
