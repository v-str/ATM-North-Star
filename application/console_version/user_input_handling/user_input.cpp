#include "user_input.h"

#include <iostream>

int UserInput::GetValueFromUser() {
  return ConvertLineToChoice(GetLineFromUser());
}

int UserInput::ConvertLineToChoice(const string& line) {
  if (LineNotEmpty(line)) {
    try {
      return std::stoi(line);
    } catch (const std::invalid_argument&) {
    } catch (const std::out_of_range&) {
    }
  }
  return kInvalidChoice;
}

bool UserInput::LineNotEmpty(const string& str) {
  for (unsigned int i = 0; i < str.size(); ++i) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return !str.empty();
}

std::string UserInput::GetLineFromUser() {
  string line;
  getline(std::cin, line);
  return line;
}

std::string UserInput::GetDataFromUser() {
  std::string user_string;
  getline(std::cin, user_string);
  return user_string;
}
