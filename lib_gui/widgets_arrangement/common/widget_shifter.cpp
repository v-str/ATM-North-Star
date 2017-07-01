#include <widget_shifter.h>

#include <QLabel>
#include <QPushButton>
#include <QWidget>

void WidgetShifter::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void WidgetShifter::SetMainWidgetPosition(const QRect& main_widget_position) {
  main_widget_position_ = main_widget_position;
}

void WidgetShifter::ShiftLabel(double shift_coefficient,
                               unsigned int direction_flag,
                               const QRect& initial_label_geometry,
                               QLabel* label) {
  ResetShiftPosition();
  AssignShiftCoefficient(shift_coefficient);
  SetShifting(direction_flag, initial_label_geometry);
  MakeShifting(label);
}

void WidgetShifter::ShiftButton(double shift_coefficient,
                                unsigned int direction_flag,
                                const QRect& initial_button_geometry,
                                QPushButton* button) {
  ResetShiftPosition();
  AssignShiftCoefficient(shift_coefficient);
  SetShifting(direction_flag, initial_button_geometry);
  MakeShifting(button);
}

void WidgetShifter::ResetShiftPosition() {
  shift_position_ = QRect(0, 0, 0, 0);
}

void WidgetShifter::SetShifting(unsigned int direction_flag,
                                const QRect& initial_geometry) {
  shift_position_.setWidth(initial_geometry.width());
  shift_position_.setHeight(initial_geometry.height());

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
}

bool WidgetShifter::IsMainWidgetBorderCrossed() const {
  if (shift_position_.x() + shift_position_.width() >
      main_widget_position_.width()) {
    return true;
  }
  return false;
}

void WidgetShifter::AssignShiftCoefficient(double shift_coefficient) {
  if (shift_coefficient > 3.0) {
    shift_coefficient = 3.0;
  }
  if (shift_coefficient < 0.0) {
    shift_coefficient = 0.0;
  }
  shift_coefficient_ = shift_coefficient;
}

void WidgetShifter::MakeShifting(QLabel* label) {
  if (!IsMainWidgetBorderCrossed()) {
    label->move(shift_position_.x(), shift_position_.y());
  } else {
    label->move(main_widget_position_.width() - shift_position_.width(),
                main_widget_position_.height() - shift_position_.height());
  }
}

void WidgetShifter::MakeShifting(QPushButton* button) {
  if (!IsMainWidgetBorderCrossed()) {
    button->move(shift_position_.x(), shift_position_.y());
  } else {
    button->move(main_widget_position_.width() - shift_position_.width(),
                 main_widget_position_.height() - shift_position_.height());
  }
}
