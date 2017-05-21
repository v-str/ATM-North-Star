#ifndef STRING_ANALYZER_H
#define STRING_ANALYZER_H

#include <string>

class StringAnalyzer {
 public:
  enum AnalyzeCriterion { kDigits, kAlphabetSymbol, kSpaces };

  static void AmountOf(AnalyzeCriterion criterion, const std::string& string);

  static int AmountOfDigits();
  static int AmountOfAlphabeticSymbols();
  static int AmountOfSpaces();

 private:
  static int amount_of_digits_;
  static int amount_of_alphabet_symbols_;
  static int amount_of_spaces_;
};

#endif  // STRING_ANALYZER_H
