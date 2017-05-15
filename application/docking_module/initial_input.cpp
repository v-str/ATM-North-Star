#include "initial_input.h"

#include <iostream>

int InitialInput::GetValueFromUser() {
  std::string user_string = GetStringFromUser();

  if (IsContainExitCharacter(user_string)) {
    return kExit;
  }

  int user_value = 0;
  if (IsContainOnlyDigits(user_string)) {
    user_value = GetDigitsFromString(user_string);
  } else {
    return kInvalidChoice;
  }

  if (user_value == kConsoleMode || user_value == kGuiMode) {
    return user_value;
  }

  return kInvalidChoice;
}

std::string InitialInput::GetStringFromUser() {
  std::string string;
  std::getline(std::cin, string);
  return string;
}

bool InitialInput::IsContainExitCharacter(const std::string& user_string) {
  return user_string == "Q" || user_string == "q";
}

bool InitialInput::IsContainOnlyDigits(const std::string& user_string) {
  for (unsigned int i = 0; i < user_string.size(); ++i) {
    if (!isdigit(user_string[i])) {
      return false;
    }
  }
  return true;
}

int InitialInput::GetDigitsFromString(const std::string& user_string) {
  try {
    return std::stoi(user_string);
  } catch (const std::invalid_argument&) {
    return kInvalidChoice;
  } catch (const std::out_of_range&) {
    return kInvalidChoice;
  }
}
