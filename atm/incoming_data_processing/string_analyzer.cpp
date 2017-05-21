#include <string_analyzer.h>

#include <algorithm>

bool IsDigit(std::string::const_iterator it) { return isdigit(*it); }

int StringAnalyzer::AmountOfDigits(const std::string& string) {
  int digit_amount;
  for (auto i : string) {
    if (isdigit(string[i])) {
      digit_amount++;
    }
  }
  return digit_amount;
}

int StringAnalyzer::AmountOfAlphabeticSymbol(const std::string& string) {
  int alphabet_symbol_amount = 0;
  for (auto i : string) {
    if (isalpha(string[i])) {
      alphabet_symbol_amount++;
    }
  }
  return alphabet_symbol_amount;
}

int StringAnalyzer::AmountOfSpaces(const std::string& string) {
  int space_symbol = 0;
  for (int i = 0; i < string.length(); ++i) {
    if (string[i] == ' ') {
      space_symbol++;
    }
  }
  return space_symbol;
}
