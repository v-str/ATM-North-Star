#ifndef WRITER_H
#define WRITER_H

#include <string>

class Writer {
 public:
  virtual void Write(const std::string& text) = 0;

  virtual ~Writer() {}
};

#endif  // WRITER_H
