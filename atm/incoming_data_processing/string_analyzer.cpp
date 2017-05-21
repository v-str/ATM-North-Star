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

bool StringAnalyzer::IsStringContainSpecialCharacters(int length_of_string) {
  int amount_of_legal_symbols =
      amount_of_digits_ + amount_of_alphabet_symbols_ + amount_of_spaces_;

  return length_of_string != amount_of_legal_symbols;
}
