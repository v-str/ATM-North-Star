#ifndef WIDGET_SHIFTER_H
#define WIDGET_SHIFTER_H

#include <delta_size.h>

class QRect;
class QLabel;

class WidgetShifter {
 public:
  enum ShiftDirection {
    kNone = 0,
    kShiftLeft = 1,
    kShiftRight = 2,
    kShiftUp = 4,
    kShiftDown = 8
  };

  void SetDeltaSize(const DeltaSize& delta_size);

  void ShiftLabel(double shift_coefficient,
                  ShiftDirection direction,
                  const QRect& initial_geometry,
                  QLabel* label);

 private:
  double VerifyShiftCoefficient(double shift_coefficient);

  DeltaSize delta_size_;

  double shift_coefficient_ = 0.0;
};

#endif  // WIDGET_SHIFTER_H
