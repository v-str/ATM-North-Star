#ifndef TEXT_WRITER_H
#define TEXT_WRITER_H

#include "writer.h"

#include <memory>
#include <string>

class TextWriter {
 public:
  static void Write(const std::string &text);

  static void AddEmptyLine();

  static void SetWriter(std::unique_ptr<Writer> writer);

 private:
  static std::unique_ptr<Writer> CreateDefaultWriter();

  static std::unique_ptr<Writer> writer_;
};

#endif  // TEXT_WRITER_H
