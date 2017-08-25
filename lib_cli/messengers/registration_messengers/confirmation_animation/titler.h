#ifndef TITLER_H
#define TITLER_H

#include <string>

class Titler {
 public:
  static void WriteLogoTitle(const std::string title_string);
  static void WriteEnterMessage();

 private:
  static std::string kIndent;
  static const int kTextDelay = 20;
};

#endif  // TITLER_H
