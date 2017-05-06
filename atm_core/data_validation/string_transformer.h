#ifndef STRING_TRANSFORMER_H
#define STRING_TRANSFORMER_H

#include <string>

class StringTransformer {
 public:
  static int GetDigitalValueFromUser();
  static std::string GetStringFromUser();

 private:
  static int ConvertStringToDigit(const std::string& string);
  static bool StringNotEmpty(const std::string& string);

  static constexpr int kInvalidValue = -1;
};

#endif  // STRING_TRANSFORMER_H
