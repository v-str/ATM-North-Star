#include "initial_input.h"

#include <iostream>
#include <string>

int InitialInput::GetValueFromUser() {
  std::string user_enter_string = "";
  int final_user_value = 0;

  std::getline(std::cin, user_enter_string);
  if (user_enter_string == "Q" || user_enter_string == "q") return kExit;

  for (unsigned int i = 0; i < user_enter_string.size(); ++i) {
    if (!isdigit(user_enter_string[i])) {
      return kInvalidChoice;
    }
  }

  try {
    return std::stoi(user_enter_string);
  } catch (const std::invalid_argument&) {
  } catch (const std::out_of_range&) {
  }

  if (final_user_value == kConsoleMode || final_user_value == kGuiMode) {
    return final_user_value;
  }

  return kInvalidChoice;
}
