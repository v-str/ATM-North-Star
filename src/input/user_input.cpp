#include "user_input.h"

#include <iostream>

bool UserInput::SuggestUserToExit() const {
  return GetResultFromUserAboutExit();
}

bool UserInput::GetResultFromUserAboutExit() const {
  bool result_of_choice = false;
  for (;;) {
    int user_want_to_exit = GetValueFromUser();
    if (user_want_to_exit == kGoToMain) {
      break;
    } else if (user_want_to_exit == kExit) {
      result_of_choice = true;
      break;
    } else {
      user_messenger_.ShowIncorrectSumInput();
    }
  }
  return result_of_choice;
}

int UserInput::GetValueFromUser() {
  return ConvertLineToChoice(GetLineFromUser());
}

int UserInput::ConvertLineToChoice(const string &line) {
  if (LineNotEmpty(line)) {
    try {
      return std::stoi(line);
    } catch (const std::invalid_argument &) {
    }
  }
  return kInvalidChoice;
}

bool UserInput::LineNotEmpty(const string &str) {
  for (size_t i = 0; i < str.length(); ++i) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return !str.empty();
}

std::string UserInput::GetLineFromUser() {
  string line;
  getline(std::cin, line);
  return line;
}

bool UserInput::SuggestUserToExitWithConfirmationMenu() const {
  return GetResultFromUserAboutExit();
}

std::string UserInput::GetDataFromUser() {
  std::string user_string;
  getline(std::cin, user_string);
  return user_string;
}

bool UserInput::ShowIncorrectMessage() const {
  notice_messenger_.ShowIncorrectData();
  return GetResultFromUserAboutExit();
}
