#include "multiwriter.h"

MultiWriter::MultiWriter(std::vector<std::unique_ptr<Writer> > writers)
    : writers_(std::move(writers)) {}

void MultiWriter::Write(const std::string &text) {
  for (auto &writer : writers_) {
    writer->Write(text);
  }
}

// std::unique_ptr<FileWriter> MultiWriter::PrepareFileWriter(
//    const std::string name_of_file, FileWriter *file_writer) {
//  file_writer->OpenFile(name_of_file);

//  return std::unique_ptr<FileWriter>(file_writer);
//}
