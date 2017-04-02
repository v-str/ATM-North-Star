#ifndef WRITER_H
#define WRITER_H

#include <string>

class Writer {
public:
  virtual ~Writer() = default;

  virtual void Write(const std::string &text) = 0;
};

#endif // WRITER_H
