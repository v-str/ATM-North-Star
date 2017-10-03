#include <string_transformer.h>

#include <iostream>

int StringTransformer::GetDigitalValueFromUser() {
  return TrasformStringToDigit(GetStringFromUser());
}

std::string StringTransformer::GetStringFromUser() {
  std::string user_string;
  getline(std::cin, user_string);
  return user_string;
}

int StringTransformer::TrasformStringToDigit(const std::string& string) {
  if (StringNotEmpty(string)) {
    try {
      return std::stoi(string);
    } catch (const std::invalid_argument&) {
    } catch (const std::out_of_range&) {
    }
  }
  return kInvalidValue;
}

bool StringTransformer::StringNotEmpty(const std::string& string) {
  for (unsigned int i = 0; i < string.size(); ++i) {
    if (!isdigit(string[i])) {
      return false;
    }
  }
  return !string.empty();
}
