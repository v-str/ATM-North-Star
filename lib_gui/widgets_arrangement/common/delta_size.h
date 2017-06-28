#ifndef DELTA_SIZE_H
#define DELTA_SIZE_H

#include <QSize>

class DeltaSize {
 public:
  DeltaSize(int delta_width, int delta_height);

 private:
  int delta_width_ = 0;
  int delta_height_ = 0;
};

#endif  // DELTA_SIZE_H
