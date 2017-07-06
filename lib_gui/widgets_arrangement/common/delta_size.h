#ifndef DELTA_SIZE_H
#define DELTA_SIZE_H

#include <QSize>

class DeltaSize {
 public:
  DeltaSize();
  DeltaSize(int width, int height);

  void SetDeltaSize(const DeltaSize& delta_size);

  void SetWidth(int delta_width);
  void SetHeight(int delta_height);

  int Width() const;
  int Height() const;

 private:
  int width_ = 0;
  int height_ = 0;
};

#endif  // DELTA_SIZE_H
