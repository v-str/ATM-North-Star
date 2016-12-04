#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include "writer.h"

#include <fstream>
#include <string>

class FileWriter : public Writer {
 public:
  FileWriter();

  ~FileWriter();

  void OpenFile(const std::string& name_of_file);

  void Write(const std::string& text) override;

 private:
  std::ofstream* file_stream_ = nullptr;
};

#endif  // FILE_WRITER_H
