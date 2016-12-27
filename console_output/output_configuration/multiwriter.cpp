#include "multiwriter.h"

MultiWriter::MultiWriter(std::vector<std::unique_ptr<Writer>> writer)
    : writers_(std::move(writer)) {}

void MultiWriter::Write(const std::string &text) {
  for (auto &writer : writers_) {
    writer->Write(text);
  }
}

