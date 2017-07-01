#include <widget_shifter.h>

#include <QLabel>
#include <QRect>

void WidgetShifter::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void WidgetShifter::ShiftLabel(double shift_coefficient,
                               ShiftDirection direction,
                               const QRect& initial_geometry,
                               QLabel* label) {
  shift_coefficient_ = VerifyShiftCoefficient(shift_coefficient);
}

double WidgetShifter::VerifyShiftCoefficient(double shift_coefficient) {
  if (shift_coefficient > 3.0) {
    shift_coefficient = 3.0;
  }
  if (shift_coefficient < -3.0) {
    shift_coefficient = -3.0;
  }
  return shift_coefficient;
}
