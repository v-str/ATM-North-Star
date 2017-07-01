#include <widget_shifter.h>

#include <QLabel>
#include <QRect>
#include <QWidget>

void WidgetShifter::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void WidgetShifter::ShiftLabel(double shift_coefficient,
                               unsigned int direction_flag,
                               const QRect& initial_geometry,
                               QLabel* label) {
  shift_coefficient_ = VerifyShiftCoefficient(shift_coefficient);

  if (direction_flag & kNone) {
    shift_position_.setX(initial_geometry.x());
    shift_position_.setY(initial_geometry.y());
  }
  if (direction_flag & kShiftLeft) {
    shift_position_.setX(initial_geometry.x() -
                         (shift_coefficient_ * delta_size_.DeltaWidth()));
    shift_position_.setY(initial_geometry.y());
  }
  if (direction_flag & kShiftRight) {
    shift_position_.setX(initial_geometry.x() -
                         (shift_coefficient_ * delta_size_.DeltaWidth()));
    shift_position_.setY(initial_geometry.y());
  }
  if (direction_flag & kShiftUp) {
    shift_position_.setX(initial_geometry.x());
    shift_position_.setY(initial_geometry.y() -
                         (shift_coefficient_ * delta_size_.DeltaHeight()));
  }
  if (direction_flag & kShiftDown) {
    shift_position_.setX(initial_geometry.x());
    shift_position_.setY(initial_geometry.y() +
                         (shift_coefficient_ * delta_size_.DeltaHeight()));
  }
  label->move(shift_position_);
}

double WidgetShifter::VerifyShiftCoefficient(double shift_coefficient) {
  if (shift_coefficient > 3.0 || shift_coefficient < 0.0) {
    shift_coefficient = 3.0;
  }
  return shift_coefficient;
}
