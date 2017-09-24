#include "user_input_handler.h"

#include <iostream>

int UserInputHandler::GetDigitInputFromUser() {
  user_string_ = GetStringInputFromUser();

  if (IsContainOnlyDigits()) {
    int user_value = GetDigitsFromString();
    return user_value;
  }

  return kInvalidInput;
}

double UserInputHandler::GetDoubleDigitFromUser() {
  user_string_ = GetStringInputFromUser();
  if (IsConvertableToDouble()) {
    double user_value = GetDoubleDigitsFromString();
    return user_value;
  }
  return kInvalidInput;
}

std::string UserInputHandler::GetStringInputFromUser() {
  std::string string;
  std::getline(std::cin, string);
  return string;
}

bool UserInputHandler::IsContainOnlyDigits() {
  for (unsigned int i = 0; i < user_string_.size(); ++i) {
    if (!isdigit(user_string_[i])) {
      return false;
    }
  }
  return true;
}

int UserInputHandler::GetDigitsFromString() {
  if (user_string_.length() > kMaximalStringLength) {
    return kInvalidInput;
  }

  try {
    return std::stoi(user_string_);
  } catch (const std::invalid_argument&) {
    return kInvalidInput;
  } catch (const std::out_of_range&) {
    return kInvalidInput;
  }
}

bool UserInputHandler::IsConvertableToDouble() {
  int dot_count = 0;
  for (unsigned int i = 0; i < user_string_.size(); ++i) {
    if (user_string_[i] == '.') {
      dot_count++;
    }
    if (user_string_[i] == ',') {
      user_string_.replace(i, 1, ".");
      dot_count++;
    }
  }
  if (dot_count > 1) {
    return false;
  }
  if (dot_count <= 1) {
    return true;
  }
}

double UserInputHandler::GetDoubleDigitsFromString() {
  if (user_string_.length() > kMaximalStringLength) {
    return kInvalidInput;
  }

  try {
    return std::stod(user_string_);
  } catch (std::invalid_argument) {
    return kInvalidInput;
  } catch (std::out_of_range) {
    return kInvalidInput;
  }
}
