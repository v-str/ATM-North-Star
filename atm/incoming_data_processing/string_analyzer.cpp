#include <string_analyzer.h>

int StringAnalyzer::digit_amount_ = 0;

int StringAnalyzer::AmountOfDigits(const std::string& string) {
  for (auto i : string) {
    if (isdigit(string[i])) {
      digit_amount_++;
    }
  }
  return digit_amount_;
}
