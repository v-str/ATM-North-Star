#include "text_writer.h"

#include <fstream>
#include <iostream>

std::ostream *TextWriter::output_stream_ = &std::cout;

void TextWriter::Write(const std::string &text) {
  *output_stream_ << text;
  output_stream_->flush();
}

void TextWriter::SetOutputStream(std::ostream *output_stream) {
  output_stream_ = output_stream;
}
