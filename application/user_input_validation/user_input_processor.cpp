#include "user_input_processor.h"

#include <iostream>

UserInputProcessor::~UserInputProcessor() {}

int UserInputProcessor::GetUserInput() {
  std::string user_string = GetStringFromUser();

  if (IsContainOnlyDigits(user_string)) {
    int user_value = GetDigitsFromString(user_string);
    return user_value;
  }

  return kInvalidChoice;
}

std::string UserInputProcessor::GetStringFromUser() {
  std::string string;
  std::getline(std::cin, string);
  return string;
}

bool UserInputProcessor::IsContainOnlyDigits(const std::string& user_string) {
  for (unsigned int i = 0; i < user_string.size(); ++i) {
    if (!isdigit(user_string[i])) {
      return false;
    }
  }
  return true;
}

int UserInputProcessor::GetDigitsFromString(const std::string& user_string) {
  try {
    return std::stoi(user_string);
  } catch (const std::invalid_argument&) {
    return kInvalidChoice;
  } catch (const std::out_of_range&) {
    return kInvalidChoice;
  }
}
