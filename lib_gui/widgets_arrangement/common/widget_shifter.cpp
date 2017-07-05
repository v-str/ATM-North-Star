﻿#include <widget_shifter.h>

#include <QRect>
#include <QWidget>

void WidgetShifter::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void WidgetShifter::ShiftWidget(const ConversionFactor& conversion_factor,
                                const QPoint& initial_position,
                                unsigned int direction_flag,
                                QWidget* widget) {
  conversion_factor_ = conversion_factor;
  ComputeShifting(initial_position, direction_flag);
  widget->move(shift_position_);
}

void WidgetShifter::ComputeShifting(const QPoint& initial_position,
                                    unsigned int direction_flag) {
  int x = initial_position.x();
  int y = initial_position.y();

  if (direction_flag & kShiftLeft) {
    x -= (conversion_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (direction_flag & kShiftRight) {
    x += (conversion_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (direction_flag & kShiftUp) {
    y -= (conversion_factor_.YAxisFactor() * delta_size_.Height());
  }
  if (direction_flag & kShiftDown) {
    y += (conversion_factor_.YAxisFactor() * delta_size_.Height());
  }

  shift_position_.setX(x);
  shift_position_.setY(y);
}
