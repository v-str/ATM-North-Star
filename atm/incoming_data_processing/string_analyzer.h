#ifndef STRING_ANALYZER_H
#define STRING_ANALYZER_H

#include <string>

class StringAnalyzer {
 public:
  static void AnalyzeString(const std::string& string);

  static int AmountOfDigits();
  static int AmountOfAlphabeticSymbols();
  static int AmountOfSpaces();

 private:
  static bool IsSpecialSymbols(int length_of_string);

  static int amount_of_digits_;
  static int amount_of_alphabet_symbols_;
  static int amount_of_spaces_;

  static bool is_special_symbols_;
};

#endif  // STRING_ANALYZER_H
