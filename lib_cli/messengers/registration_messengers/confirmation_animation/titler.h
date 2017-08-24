#ifndef TITLER_H
#define TITLER_H

#include <string>

class Titler {
 public:
  static void WriteTitle(const std::string title_string);

 private:
  static std::string kIndent;
};

#endif  // TITLER_H
