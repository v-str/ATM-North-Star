#include <widget_shifter.h>

#include <QRect>
#include <QWidget>

#include <QDebug>

void WidgetShifter::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void WidgetShifter::ShiftWidget(double x_shift_coefficient,
                                double y_shift_coefficient,
                                unsigned int direction_flag,
                                const QPoint initial_position,
                                QWidget* widget) {
  CheckCoefficient(x_shift_coefficient, y_shift_coefficient);
  ComputeShifting(direction_flag, initial_position);
  widget->move(shift_position_);
}

void WidgetShifter::CheckCoefficient(double x_shift_coefficient,
                                     double y_shift_coefficient) {
  if (x_shift_coefficient >= kMaxShiftCoefficient) {
    x_shift_coefficient_ = kMaxShiftCoefficient;
  } else if (x_shift_coefficient <= kMinShiftCoefficient) {
    x_shift_coefficient_ = kMinShiftCoefficient;
  } else {
    x_shift_coefficient_ = x_shift_coefficient;
  }

  if (y_shift_coefficient >= kMaxShiftCoefficient) {
    y_shift_coefficient_ = kMaxShiftCoefficient;
  } else if (x_shift_coefficient <= kMinShiftCoefficient) {
    y_shift_coefficient = kMinShiftCoefficient;
  } else {
    y_shift_coefficient_ = y_shift_coefficient;
  }
}

void WidgetShifter::ComputeShifting(unsigned int direction_flag,
                                    QPoint initial_position) {
  int x = initial_position.x();
  int y = initial_position.y();

  if (direction_flag & kShiftLeft) {
    x -= (x_shift_coefficient_ * delta_size_.DeltaWidth());
  }
  if (direction_flag & kShiftRight) {
    x += (x_shift_coefficient_ * delta_size_.DeltaWidth());
  }
  if (direction_flag & kShiftUp) {
    y -= (y_shift_coefficient_ * delta_size_.DeltaHeight());
  }
  if (direction_flag & kShiftDown) {
    y += (y_shift_coefficient_ * delta_size_.DeltaHeight());
  }

  shift_position_.setX(x);
  shift_position_.setY(y);
}
