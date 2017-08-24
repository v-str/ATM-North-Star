#ifndef TITLER_H
#define TITLER_H

#include <string>

class Titler {
 public:
  Titler(const std::string& title_string);

  void WriteTitle() const;

 private:
  std::string title_string_;
};

#endif  // TITLER_H
