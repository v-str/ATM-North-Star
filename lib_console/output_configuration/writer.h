#ifndef WRITER_H
#define WRITER_H

#include <string>

class Writer {
 public:
  virtual ~Writer() = 0;

  virtual void Write(const std::string& text) = 0;
};

#endif  // WRITER_H
