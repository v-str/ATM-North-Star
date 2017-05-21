#ifndef STRING_ANALYZER_H
#define STRING_ANALYZER_H

#include <string>

class StringAnalyzer {
 public:
  static int AmountOfDigits(const std::string& string);
  static int AmountOfAlphabeticSymbol(const std::string& string);
  static int AmountOfSpaces(const std::string& string);
};

#endif  // STRING_ANALYZER_H
