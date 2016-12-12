#ifndef MULTIWRITER_H
#define MULTIWRITER_H

#include "file_writer.h"
#include "writer.h"

#include <memory>
#include <vector>

class MultiWriter : public Writer {
 public:
  explicit MultiWriter(std::vector<std::unique_ptr<Writer> > writers);

  void Write(const std::string& text) override;

 private:
  std::unique_ptr<FileWriter> PrepareFileWriter(const std::string &name_of_file,
                                                FileWriter* file_writer);

  std::vector<std::unique_ptr<Writer> > writers_;
};

#endif  // MULTIWRITER_H
