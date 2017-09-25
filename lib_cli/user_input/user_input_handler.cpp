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
  bool is_convertable = true;

  for (unsigned int i = 0; i < user_string_.size(); ++i) {
    if (!IsStringCorrect(i)) {
      is_convertable = false;
    }
  }

  return is_convertable;
}

bool UserInputHandler::IsStringCorrect(int index) {
  if (IsComma(index)) {
    user_string_.replace(index, 1, ".");
  }

  if (!isdigit(user_string_[index])) {
    if (!IsDot(index)) {
      return false;
    }
  }
  return true;
}

bool UserInputHandler::IsDot(int index) { return user_string_[index] == '.'; }

bool UserInputHandler::IsComma(int index) { return user_string_[index] == ','; }

void UserInputHandler::SubstituteCommaByDot() {}

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
