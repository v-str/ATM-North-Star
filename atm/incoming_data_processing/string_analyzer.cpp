#include <string_analyzer.h>

#include <algorithm>

void StringAnalyzer::AnalyzeString(const std::string& string) {
  SetToZeroValues();

  for (auto symbol : string) {
    if (isdigit(symbol)) amount_of_digits_++;
    if (isalpha(symbol)) amount_of_alphabet_symbols_++;
    if (symbol == space_symbol_) amount_of_spaces_++;
  }

  is_special_symbols_ = IsStringContainSpecialSymbols(string.length());
  is_adjacent_spaces_ = IsStringContainAdjacentSpaces(string);
  is_begin_with_space_ = (*string.begin() == space_symbol_);
  is_end_with_space_ = (*(--string.end()) == space_symbol_);
  is_only_digits_ = IsStringContainOnlyDigits(string.length());
  is_string_empty_ = string.empty();
}

int StringAnalyzer::AmountOfDigits() const { return amount_of_digits_; }

int StringAnalyzer::AmountOfAlphabeticSymbols() const {
  return amount_of_alphabet_symbols_;
}

int StringAnalyzer::AmountOfSpaces() const { return amount_of_spaces_; }

bool StringAnalyzer::IsStringContainSpecialSymbols() const {
  return is_special_symbols_;
}

bool StringAnalyzer::IsStringContainAdjacentSpaces() const {
  return is_adjacent_spaces_;
}

bool StringAnalyzer::IsStringContainOnlyDigits() const {
  return is_only_digits_;
}

bool StringAnalyzer::IsStringBeginWithSpace() const {
  return is_begin_with_space_;
}

bool StringAnalyzer::IsStringEndWithSpace() const { return is_end_with_space_; }

bool StringAnalyzer::IsStringEmpty() const { return is_string_empty_; }

bool StringAnalyzer::IsStringContainOnlyDigits(int length_of_string) const {
  return length_of_string - amount_of_digits_ == amount_of_spaces_;
}

bool StringAnalyzer::IsStringContainSpecialSymbols(int length_of_string) const {
  int amount_of_legal_symbols =
      amount_of_digits_ + amount_of_alphabet_symbols_ + amount_of_spaces_;

  return length_of_string != amount_of_legal_symbols;
}

bool StringAnalyzer::IsStringContainAdjacentSpaces(
    const std::string& string) const {
  std::string temp_string = string;
  std::string::iterator it = std::adjacent_find(
      temp_string.begin(), temp_string.end(), [](char one, char two) {
        return one == space_symbol_ && two == space_symbol_;
      });

  return it != temp_string.end();
}

void StringAnalyzer::SetToZeroValues() {
  amount_of_digits_ = 0;
  amount_of_alphabet_symbols_ = 0;
  amount_of_spaces_ = 0;

  is_special_symbols_ = true;
  is_begin_with_space_ = true;
  is_end_with_space_ = true;
  is_adjacent_spaces_ = true;
  is_only_digits_ = true;
}
