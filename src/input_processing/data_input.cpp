#include "data_input.h"

#include <iostream>

bool DataInput::SuggestUserToExit() const {
  user_messenger_.ShowSuggestionAboutExit();
  return GetResultFromUserAboutExit();
}

bool DataInput::GetResultFromUserAboutExit() const {
  bool result_of_choice = false;
  for (;;) {
    int user_want_to_exit = GetChoiceFromUser();
    if (user_want_to_exit == kGoToMain) {
      break;
    } else if (user_want_to_exit == kExit) {
      utility_.Sleep(kSecond);
      result_of_choice = true;
      break;
    } else {
      user_messenger_.ShowIncorrectSumInput();
    }
  }
  return result_of_choice;
}

int DataInput::GetChoiceFromUser() const {
  return ConvertLineToChoice(GetLineFromUser());
}

int DataInput::ConvertLineToChoice(const string &line) const {
  if (LineNotEmpty(line)) {
    try {
      return std::stoi(line);
    } catch (const std::invalid_argument &) {
    }
  }
  return kInvalidChoice;
}

bool DataInput::LineNotEmpty(const string &str) const {
  for (size_t i = 0; i < str.length(); ++i) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return !str.empty();
}

std::string DataInput::GetLineFromUser() const {
  string line;
  getline(std::cin, line);
  return line;
}

bool DataInput::SuggestUserToExitWithConfirmationMenu() {
  return GetResultFromUserAboutExit();
}

bool DataInput::ShowIncorrectMessage() const {
  error_message.NoticeAboutIncorrectDataMessage();
  return GetResultFromUserAboutExit();
}
