#include <authentication_messenger.h>

#include <string>

#include <console_editor.h>

void AuthenticationMessenger::DisplayLoginText() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\n\n\tLogin: ", kDelay);
}

void AuthenticationMessenger::DisplayPasswordText() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\tPassword: ", kDelay);
}

void AuthenticationMessenger::CorrectLoginMessage() {
  WriteLoginTitleStatus();
  ConsoleEditor::WriteText("\tCorrect");
}

void AuthenticationMessenger::LoginLength(StringLength login_length) {
  std::string length_status = "";

  switch (login_length) {
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
  WriteLoginTitleStatus();
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

void AuthenticationMessenger::CorrectPasswordMessage() {
  WritePasswordTitleStatus();
  ConsoleEditor::WriteTextWithDelayPerSymbol("\tCorrect");
}

void AuthenticationMessenger::PasswordLength(StringLength password_length) {
  std::string password_status = "";

  switch (password_length) {
    case kShortPasswordLength:
      password_status = "shorter";
      break;
    case kLongPasswordLength:
      password_status = "longer";
    default:
      break;
  }

  WritePasswordTitleStatus();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      " Your password is " + password_status +
      " than required,\n"
      " Password must be strictly 6 symbols.\n"
      " It may contain both latin alphabet symbols and digits.");
}

void AuthenticationMessenger::PasswordContainSpaceSymbol() {
  WritePasswordTitleStatus();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      " Password contain space symbol.\n"
      " Please remove unnecessary symbols and try again.");
}

void AuthenticationMessenger::PasswordEmpty() {
  WritePasswordTitleStatus();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      " Password is emptyn.\n"
      " Please enter a valid password and try again");
}

void AuthenticationMessenger::ClearScreen() { ConsoleEditor::ClearScreen(); }

void AuthenticationMessenger::AddEmptyLines(int amount_of_lines) {
  ConsoleEditor::AddEmptyLineNTimes(amount_of_lines);
}

void AuthenticationMessenger::WriteLoginTitleStatus() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n Login status: \n"
      "---------------------\n");
}

void AuthenticationMessenger::WritePasswordTitleStatus() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\n Password status: \n"
      "---------------------\n");
}
