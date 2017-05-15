#include "initial_input.h"

#include <iostream>

int InitialInput::GetValueFromUser() {
  std::string user_enter_string = GetStringFromUser();

  if (IsContainExitCharacter(user_enter_string)) {
    return kExit;
  }

  int final_user_value = 0;
  if (IsContainOnlyDigits(user_enter_string)) {
    final_user_value = ConvertToDigit(user_enter_string);
  } else {
    return kInvalidChoice;
  }

  if (final_user_value == kConsoleMode || final_user_value == kGuiMode) {
    return final_user_value;
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

int InitialInput::ConvertToDigit(const std::string& user_string) {
  try {
    return std::stoi(user_string);
  } catch (const std::invalid_argument&) {
    return kInvalidChoice;
  } catch (const std::out_of_range&) {
    return kInvalidChoice;
  }
}
