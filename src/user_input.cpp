#include "user_input.h"

#include <iostream>
#include <string>

#include "system_utility.h"

using std::cin;
using std::cout;
using std::string;

const int kInvalidChoice = 0;
const int kExit = 2;
const int kgo_to_main = 1;

bool UserInput::SuggestUserToExit() const {
  WriteTextWithDelay(
      "# 1. Exit to start demo page.\n"
      "# 2. Exit program.\n");
  cout << "# Enter: ";

  return GetResultFromUser();
}

bool UserInput::GetResultFromUser() const {
  bool result_of_choice = false;
  int user_want_to_exit = GetValueFromUser();
  for (;;) {
    if (user_want_to_exit == kgo_to_main) {
      break;
    } else if (user_want_to_exit == kExit) {
      ShowExitMessage();
      Sleep(1000);
      result_of_choice = true;
      break;
    } else {
      cout << "# Incorrect input, please try again:\n"
              "# Enter: ";
      user_want_to_exit = GetValueFromUser();
    }
  }

  return result_of_choice;
}

int UserInput::GetValueFromUser() const {
  return ConvertLineToChoice(GetLineFromUser());
}

int UserInput::ConvertLineToChoice(const string &line) const {
  if (LineNotEmpty(line)) {
    try {
      return std::stoi(line);
    } catch (const std::invalid_argument &) {
    }
  }

  return kInvalidChoice;
}

bool UserInput::LineNotEmpty(const string &str) const {
  for (size_t i = 0; i < str.length(); ++i) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return !str.empty();
}

string UserInput::GetLineFromUser() const {
  string line;
  getline(cin, line);

  return line;
}

void UserInput::ShowExitMessage() const {
  WriteTextWithDelay(
      "\n# Thank you for using our ATM system,\n"
      "# have a nice day!\n\n");
}
