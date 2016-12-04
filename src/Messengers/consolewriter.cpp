#include "consolewriter.h"

ConsoleWriter::ConsoleWriter() : console_stream_(&std::cout) {}

void ConsoleWriter::Write(const std::string& text) {
  *console_stream_ << text;
  console_stream_->flush();
}