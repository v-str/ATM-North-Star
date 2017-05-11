#ifndef STRING_PARSER_H
#define STRING_PARSER_H

#include <string>

class StringParser {
 public:
  static void ModifyString(const char border_symbol,
                           int string_limit_length,
                           const std::string& string);
};

#endif  // STRING_PARSER_H
