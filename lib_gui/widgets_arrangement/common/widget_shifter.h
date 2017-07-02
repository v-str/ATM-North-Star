#ifndef WIDGET_SHIFTER_H
#define WIDGET_SHIFTER_H

#include <QPoint>
#include <QRect>

#include <delta_size.h>
#include <shift_coefficient.h>

class QWidget;
class QRect;

class WidgetShifter {
 public:
  enum ShiftDirection {
    kShiftLeft = 1,
    kShiftRight = 2,
    kShiftUp = 4,
    kShiftDown = 8
  };

  void SetDeltaSize(const DeltaSize& delta_size);

  void ShiftWidget(const ShiftCoefficient& shift_coefficient,
                   unsigned int direction_flag,
                   const QPoint initial_position,
                   QWidget* widget);

 private:
  void ComputeShifting(unsigned int direction_flag, QPoint initial_position);

  DeltaSize delta_size_;
  ShiftCoefficient shift_coefficient_;
  QPoint shift_position_;

  static constexpr double kMaxShiftCoefficient = 3.0;
  static constexpr double kMinShiftCoefficient = 0.0;
};

#endif  // WIDGET_SHIFTER_H
