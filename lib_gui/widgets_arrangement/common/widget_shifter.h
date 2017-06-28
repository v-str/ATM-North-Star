#ifndef WIDGET_SHIFTER_H
#define WIDGET_SHIFTER_H

#include <delta_size.h>

class WidgetShifter {
 public:
  void SetDeltaSize(const DeltaSize& delta_size);

 private:
  DeltaSize delta_size_;

  double shift_coefficient_ = 0.0;
};

#endif  // WIDGET_SHIFTER_H
