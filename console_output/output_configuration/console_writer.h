#ifndef CONSOLE_WRITER_H
#define CONSOLE_WRITER_H

#include <iostream>
#include <string>

#include "writer.h"

class ConsoleWriter : public Writer {
 public:
  ConsoleWriter();

  void Write(const std::string& text) override;

 private:
  std::ostream* console_stream_ = nullptr;
};

#endif  // CONSOLE_WRITER_H
