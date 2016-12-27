#ifndef MULTIWRITER_H
#define MULTIWRITER_H

#include "file_writer.h"
#include "writer.h"

#include <memory>
#include <vector>

class MultiWriter : public Writer {
 public:
  explicit MultiWriter(std::vector<std::unique_ptr<Writer> > writer);

  void Write(const std::string& text) override;

 private:
  std::vector<std::unique_ptr<Writer>> writers_;
};

#endif  // MULTIWRITER_H
