#include <string_analyzer.h>

#include <algorithm>

void StringAnalyzer::AnalyzeString(const std::string& string) {
  SetToZeroValues();

  for (auto i : string) {
    if (isdigit(string[i])) amount_of_digits_++;
    if (isalpha(string[i])) amount_of_alphabet_symbols_++;
    if (string[i] == ' ') amount_of_spaces_++;
  }

  is_special_symbols_ = IsStringContainSpecialSymbols(string.length());
  is_begin_with_space_ = (*string.begin() == ' ');
  is_end_with_space_ = (*string.end() == ' ');
}

int StringAnalyzer::AmountOfDigits() const { return amount_of_digits_; }

int StringAnalyzer::AmountOfAlphabeticSymbols() const {
  return amount_of_alphabet_symbols_;
}

int StringAnalyzer::AmountOfSpaces() const { return amount_of_spaces_; }

bool StringAnalyzer::IsStringContainSpecialSymbols() const {
  return is_special_symbols_;
}

bool StringAnalyzer::IsStringBeginWithSpace() const {
  return is_begin_with_space_;
}

bool StringAnalyzer::IsStringEndWithSpace() const { return is_end_with_space_; }

bool StringAnalyzer::IsStringContainSpecialSymbols(int length_of_string) {
  int amount_of_legal_symbols =
      amount_of_digits_ + amount_of_alphabet_symbols_ + amount_of_spaces_;

  return length_of_string != amount_of_legal_symbols;
}

void StringAnalyzer::SetToZeroValues() {
  amount_of_digits_ = 0;
  amount_of_alphabet_symbols_ = 0;
  amount_of_spaces_ = 0;
}
