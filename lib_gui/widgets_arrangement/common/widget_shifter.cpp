#include <widget_shifter.h>

#include <QLabel>
#include <QRect>

void WidgetShifter::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void WidgetShifter::ShiftLabel(double shift_coefficient,
                               unsigned int direction,
                               const QRect& initial_geometry,
                               QLabel* label) {
  shift_coefficient_ = VerifyShiftCoefficient(shift_coefficient);

  if (direction & kNone) {
    label->setGeometry(initial_geometry);
  }
  if (direction & kShiftLeft) {
    label->setGeometry(
        initial_geometry.x() - (shift_coefficient_ * delta_size_.DeltaWidth()),
        initial_geometry.y(), initial_geometry.width(),
        initial_geometry.height());
  }
  if (direction & kShiftRight) {
    label->setGeometry(
        initial_geometry.x() + (shift_coefficient_ * delta_size_.DeltaWidth()),
        initial_geometry.y(), initial_geometry.width(),
        initial_geometry.height());
  }
  if (direction & kShiftUp) {
    label->setGeometry(
        initial_geometry.x(),
        initial_geometry.y() - (shift_coefficient_ * delta_size_.DeltaHeight()),
        initial_geometry.width(), initial_geometry.height());
  }
  if (direction & kShiftDown) {
    label->setGeometry(
        initial_geometry.x(),
        initial_geometry.y() + (shift_coefficient_ * delta_size_.DeltaHeight()),
        initial_geometry.width(), initial_geometry.height());
  }
}

double WidgetShifter::VerifyShiftCoefficient(double shift_coefficient) {
  if (shift_coefficient > 3.0 || shift_coefficient < 0.0) {
    shift_coefficient = 3.0;
  }
  return shift_coefficient;
}
