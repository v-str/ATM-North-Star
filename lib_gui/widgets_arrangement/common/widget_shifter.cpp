#include <widget_shifter.h>

#include <QRect>
#include <QWidget>

void WidgetShifter::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void WidgetShifter::ShiftWidget(double shift_coefficient,
                                unsigned int direction_flag,
                                const QPoint initial_position,
                                QWidget* widget) {
  CheckShiftCoefficient(shift_coefficient);
  ComputeShifting(direction_flag, initial_position);
  widget->move(shift_position_);
}

void WidgetShifter::CheckShiftCoefficient(double shift_coefficient) {
  if (shift_coefficient > kMaxShiftCoefficient) {
    shift_coefficient_ = kMaxShiftCoefficient;
  } else if (shift_coefficient < kMinShiftCoefficient) {
    shift_coefficient_ = kMinShiftCoefficient;
  } else {
    shift_coefficient_ = shift_coefficient;
  }
}

void WidgetShifter::ComputeShifting(unsigned int direction_flag,
                                    QPoint initial_position) {
  int x = initial_position.x();
  int y = initial_position.y();

  if (direction_flag & kShiftLeft) {
    x -= (shift_coefficient_ * delta_size_.DeltaWidth());
  }
  if (direction_flag & kShiftRight) {
    x += (shift_coefficient_ * delta_size_.DeltaWidth());
  }
  if (direction_flag & kShiftUp) {
    y -= (shift_coefficient_ * delta_size_.DeltaHeight());
  }
  if (direction_flag & kShiftDown) {
    y += (shift_coefficient_ * delta_size_.DeltaHeight());
  }

  shift_position_.setX(x);
  shift_position_.setY(y);
}
