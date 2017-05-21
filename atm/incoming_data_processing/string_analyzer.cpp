#include <string_analyzer.h>

#include <algorithm>

int StringAnalyzer::amount_of_digits_ = 0;
int StringAnalyzer::amount_of_alphabet_symbols_ = 0;
int StringAnalyzer::amount_of_spaces_ = 0;

void StringAnalyzer::AmountOf(StringAnalyzer::AnalyzeCriterion criterion,
                              const std::string& string) {
  amount_of_digits_ = 0;
  amount_of_alphabet_symbols_ = 0;
  amount_of_spaces_ = 0;

  for (auto i : string) {
    switch (criterion) {
      case kDigits:
        if (isdigit(string[i])) amount_of_digits_++;
        break;
      case kAlphabetSymbol:
        if (isalpha(string[i])) amount_of_alphabet_symbols_++;
        break;
      case kSpaces:
        if (string[i] == ' ') amount_of_spaces_++;
        break;
      default:
        break;
    }
  }
}
