#ifndef TEXT_WRITER_H
#define TEXT_WRITER_H

#include <string>

class TextWriter {
 public:
  static void Write(const std::string &text);

  static void SetOutputStream(std::ostream *output_stream);

 private:
  static std::ostream *output_stream_;
};

#endif  // TEXT_WRITER_H
