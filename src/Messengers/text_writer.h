#ifndef TEXTWRITER_H
#define TEXTWRITER_H

#include <string>

class TextWriter {
  enum WriteCondition { kConsoleOutput, kFileOutput };

 public:
  static void Write(const std::string &);

  static void SetOutput(int output);

 private:
  static int output_condition_;
};

#endif  // TEXTWRITER_H
