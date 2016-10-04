#include "user_input.h"

static const int kInvalidChoice = -1;
static const int kGoToMain = 1;
static const int kExit = 2;
static const int kSecond = 1000;

bool UserInput::SuggestUserToExit() const {
  user_messenger_.ShowSuggestionAboutExit();
  return GetResultFromUserAboutExit();
}

bool UserInput::GetResultFromUserAboutExit() const {
  bool result_of_choice = false;
  for (;;) {
    int user_want_to_exit = GetChoiceFromUser();
    if (user_want_to_exit == kGoToMain) {
      break;
    } else if (user_want_to_exit == kExit) {
      //      ShowExitMessage();
      utility_.Sleep(kSecond);
      result_of_choice = true;
      break;
    } else {
      user_messenger_.ShowIncorrectSumInput();
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

// void UserInput::ShowExitMessage() const {
//  utility_.WriteTextWithDelay("\n\t# Thank you for using our ATM system\n");
//}

bool UserInput::SuggestUserToExitWithConfirmationMenu() {
  return GetResultFromUserAboutExit();
}

bool UserInput::ShowIncorrectMessage() const {
  error_message.NoticeAboutIncorrectDataMessage();
  return GetResultFromUserAboutExit();
}
