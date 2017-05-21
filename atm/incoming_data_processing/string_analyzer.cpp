#include <string_analyzer.h>

int StringAnalyzer::digit_amount_ = 0;
int StringAnalyzer::alphabet_symbol_amount_ = 0;

int StringAnalyzer::AmountOfDigits(const std::string& string) {
  for (auto i : string) {
    if (isdigit(string[i])) {
      digit_amount_++;
    }
  }
  return digit_amount_;
}

int StringAnalyzer::AmountOfAlphabeticSymbol(const std::string& string) {
  for (auto i : string) {
    if (isalpha(string[i])) {
      alphabet_symbol_amount_++;
    }
  }
  return alphabet_symbol_amount_;
}
