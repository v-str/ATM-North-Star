#include "menu_input_processor.h"

#include <iostream>

int MenuInputProcessor::GetMenuItem() {
  std::string user_string = GetStringFromUser();

  if (IsContainExitCharacter(user_string)) {
    return kQuit;
  }

  if (IsContainOnlyDigits(user_string)) {
    int user_value = GetDigitsFromString(user_string);
    return user_value;
  }

  return kInvalidChoice;
}

std::string MenuInputProcessor::GetStringFromUser() {
  std::string string;
  std::getline(std::cin, string);
  return string;
}

bool MenuInputProcessor::IsContainExitCharacter(
    const std::string& user_string) {
  if (user_string == "Quit" || user_string == "quit") {
    return true;
  }

  if (user_string == "Q" || user_string == "q") {
    return true;
  }

  return false;
}

bool MenuInputProcessor::IsContainOnlyDigits(const std::string& user_string) {
  for (unsigned int i = 0; i < user_string.size(); ++i) {
    if (!isdigit(user_string[i])) {
      return false;
    }
  }
  return true;
}

int MenuInputProcessor::GetDigitsFromString(const std::string& user_string) {
  try {
    return std::stoi(user_string);
  } catch (const std::invalid_argument&) {
    return kInvalidChoice;
  } catch (const std::out_of_range&) {
    return kInvalidChoice;
  }
}
