#include <widget_shifter.h>

#include <QLabel>
#include <QRect>

void WidgetShifter::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void WidgetShifter::ShiftLabel(double shift_coefficient,
                               ShiftDirection direction,
                               const QRect& initial_geometry,
                               QLabel* label) {}
