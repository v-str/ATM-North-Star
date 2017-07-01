#include <widget_shifter.h>

#include <QLabel>
#include <QWidget>

void WidgetShifter::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void WidgetShifter::SetMainWidgetPosition(const QRect& main_widget_position) {
  main_widget_position_ = main_widget_position;
}

void WidgetShifter::ShiftLabel(double shift_coefficient,
                               unsigned int direction_flag,
                               const QRect& initial_geometry,
                               QLabel* label) {
  shift_coefficient_ = AssignShiftCoefficient(shift_coefficient);

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

  shift_position_.setWidth(initial_geometry.width());
  shift_position_.setHeight(initial_geometry.height());

  if (IsMainWidgetBorderCrossed()) {
    label->move(shift_position_.x(), shift_position_.y());
  }
}

bool WidgetShifter::IsMainWidgetBorderCrossed() const {
  if (shift_position_.x() + shift_position_.width() <=
      main_widget_position_.width()) {
    return true;
  }
  return false;
}

double WidgetShifter::AssignShiftCoefficient(double shift_coefficient) {
  if (shift_coefficient > 3.0 || shift_coefficient < 0.0) {
    shift_coefficient = 3.0;
  }
  return shift_coefficient;
}
