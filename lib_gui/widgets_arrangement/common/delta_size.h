#ifndef DELTA_SIZE_H
#define DELTA_SIZE_H

#include <QSize>

class DeltaSize {
 public:
  DeltaSize(int delta_width, int delta_height);

  void SetDeltaWidth(int delta_width);
  void SetDeltaHeight(int delta_height);

  int DeltaWidth() const;
  int DeltaHeight() const;

 private:
  int delta_width_ = 0;
  int delta_height_ = 0;
};

#endif  // DELTA_SIZE_H
