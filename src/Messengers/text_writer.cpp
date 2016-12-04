#include "text_writer.h"
#include "consolewriter.h"

#include <fstream>
#include <iostream>

std::unique_ptr<Writer> TextWriter::writer_ = TextWriter::CreateDefaultWriter();

void TextWriter::Write(const std::string &text) { writer_->Write(text); }

void TextWriter::SetWriter(std::unique_ptr<Writer> writer) {
  writer_ = std::move(writer);
}

std::unique_ptr<Writer> TextWriter::CreateDefaultWriter() {
  return std::unique_ptr<Writer>(new ConsoleWriter);
}
