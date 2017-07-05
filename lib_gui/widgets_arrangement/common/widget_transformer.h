#ifndef WIDGET_TRANSFORMER_H
#define WIDGET_TRANSFORMER_H

#include <QPoint>
#include <QRect>

#include <conversion_factor.h>
#include <delta_size.h>

class QWidget;
class QRect;

class WidgetTransformer {
 public:
  enum ShiftDirection {
    kShiftLeft = 1,
    kShiftRight = 2,
    kShiftUp = 4,
    kShiftDown = 8
  };

  void SetDeltaSize(const DeltaSize& delta_size);

  void ShiftWidget(const ConversionFactor& conversion_factor,
                   const QRect& initial_position,
                   unsigned int direction_flag,
                   QWidget* widget);

 private:
  void ComputeShifting(const QRect& initial_position,
                       unsigned int direction_flag);

  DeltaSize delta_size_;
  ConversionFactor conversion_factor_;
  QPoint shift_position_;
};

#endif  // WIDGET_TRANSFORMER_H
