#ifndef STRING_ANALYZER_H
#define STRING_ANALYZER_H

#include <string>

class StringAnalyzer {
 public:
  static int AmountOfDigits(const std::string& string);
  static int AmountOfAlphabeticSymbol(const std::string& string);

 private:
  static int digit_amount_;
  static int alphabet_symbol_amount_;
};

#endif  // STRING_ANALYZER_H
