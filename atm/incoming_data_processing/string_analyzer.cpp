#include <string_analyzer.h>

#include <algorithm>

int StringAnalyzer::amount_of_digits_ = 0;
int StringAnalyzer::amount_of_alphabet_symbols_ = 0;
int StringAnalyzer::amount_of_spaces_ = 0;

void StringAnalyzer::AnalyzeString(const std::string& string) {
  amount_of_digits_ = 0;
  amount_of_alphabet_symbols_ = 0;
  amount_of_spaces_ = 0;

  for (auto i : string) {
    if (isdigit(string[i])) amount_of_digits_++;
    if (isalpha(string[i])) amount_of_alphabet_symbols_++;
    if (string[i] == ' ') amount_of_spaces_++;
  }
}

int StringAnalyzer::AmountOfDigits() { return amount_of_digits_; }

int StringAnalyzer::AmountOfAlphabeticSymbols() {
  return amount_of_alphabet_symbols_;
}

int StringAnalyzer::AmountOfSpaces() { return amount_of_spaces_; }
