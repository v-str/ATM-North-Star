#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include <fstream>
#include <string>

#include "writer.h"

class FileWriter : public Writer {
 public:
  FileWriter();
  explicit FileWriter(const std::string& name_of_file);

  ~FileWriter();

  void OpenFile(const std::string& name_of_file);

  void Write(const std::string& text) override;

 private:
  std::ofstream* file_stream_ = nullptr;
};

#endif  // FILE_WRITER_H
