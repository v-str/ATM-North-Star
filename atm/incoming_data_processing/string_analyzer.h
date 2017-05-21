#ifndef STRING_ANALYZER_H
#define STRING_ANALYZER_H

#include <string>

class StringAnalyzer {
 public:
  void AnalyzeString(const std::string& string);

  int AmountOfDigits() const;
  int AmountOfAlphabeticSymbols() const;
  int AmountOfSpaces() const;

  bool IsStringContainSpecialSymbols() const;

 private:
  bool IsStringContainSpecialSymbols(int length_of_string);

  void SetToZeroValues();

  int amount_of_digits_ = 0;
  int amount_of_alphabet_symbols_ = 0;
  int amount_of_spaces_ = 0;

  bool is_special_symbols_ = true;
};

#endif  // STRING_ANALYZER_H
