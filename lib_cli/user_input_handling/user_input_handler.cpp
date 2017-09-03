#include "user_input_handler.h"

#include <iostream>

int UserInputHandler::GetDigitInputFromUser() {
  std::string user_string = GetStringInputFromUser();

  if (IsContainOnlyDigits(user_string)) {
    int user_value = GetDigitsFromString(user_string);
    return user_value;
  }

  return kInvalidInput;
}

std::string UserInputHandler::GetStringInputFromUser() {
  std::string string;
  std::getline(std::cin, string);
  return string;
}

bool UserInputHandler::IsContainOnlyDigits(const std::string& user_string) {
  for (unsigned int i = 0; i < user_string.size(); ++i) {
    if (!isdigit(user_string[i])) {
      return false;
    }
  }
  return true;
}

int UserInputHandler::GetDigitsFromString(const std::string& user_string) {
  if (user_string.length() > kMaximalStringLength) {
    return kInvalidInput;
  }

  try {
    return std::stoi(user_string);
  } catch (const std::invalid_argument&) {
    return kInvalidInput;
  } catch (const std::out_of_range&) {
    return kInvalidInput;
  }
}
