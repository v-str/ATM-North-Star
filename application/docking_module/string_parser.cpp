#include "string_parser.h"

#include <sstream>

void StringParser::ModifyString(const char border_symbol,
                                int string_limit_length,
                                const std::string& string) {
  std::stringstream stream;
  stream << border_symbol << " " << string;

  std::string new_string = stream.str();

  if (static_cast<int>(new_string.length()) > string_limit_length) {
    // something
  } else if (static_cast<int>(new_string.length()) < string_limit_length) {
    // something
  } else if (static_cast<int>(new_string.length()) == string_limit_length) {
    // something
  }
}
