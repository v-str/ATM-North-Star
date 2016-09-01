#include "user_input.h"

#include <iostream>
#include <string>

#include "system_utility.h"
#include "demo_message_set.h"

using std::cin;
using std::cout;
using std::string;

static const int kInvalidChoice = -1;
static const int kExit = 2;
static const int kgo_to_main = 1;

bool UserInput::SuggestUserToExit() const {
  WriteTextWithDelay(
      "\n\t# 1. Exit to main page.\n"
      "\t# 2. Exit program.\n");
  cout << "\t# Enter: ";

  return GetResultFromUserAboutExit();
}

bool UserInput::GetResultFromUserAboutExit() const {
  bool result_of_choice = false;
  for (;;) {
    int user_want_to_exit = GetChoiceFromUser();
    if (user_want_to_exit == kgo_to_main) {
      break;
    } else if (user_want_to_exit == kExit) {
      ShowExitMessage();
      Sleep(1000);
      result_of_choice = true;
      break;
    } else {
      cout << "\t# Incorrect input, please try again:\n"
              "\t# Enter: ";
    }
  }

  return result_of_choice;
}

int UserInput::GetChoiceFromUser() const {
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
      "\n\t# Thank you for using our ATM system\n");
}

bool UserInput::ShowIncorrectMessage() const {
  WriteTextWithDelay(
      "\n\t# Data is not correct,\n"
      "\t# return to main?\n"
      "\t# 1. Yes\n"
      "\t# 2. No, exit");
  cout << "\t# Enter: ";
  cin.clear();
  return GetResultFromUserAboutExit();
}
