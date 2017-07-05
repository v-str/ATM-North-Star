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
  enum ManipulationSide { kLeft = 1, kRight = 2, kUp = 4, kDown = 8 };

  void SetDeltaSize(const DeltaSize& delta_size);

  void ShiftWidget(const ConversionFactor& shift_factor,
                   const QRect& initial_position,
                   unsigned int manipulation_side,
                   QWidget* widget);

  void StretchWidget(const ConversionFactor& stretch_factor,
                     const QRect& initial_geometry,
                     unsigned int manipulation_side,
                     QWidget* widget);

 private:
  void ComputeShifting(const QRect& initial_position,
                       unsigned int manipulation_flag);
  void ComputeStretching(const QRect& initial_position,
                         unsigned int manipulation_flag);

  DeltaSize delta_size_;

  ConversionFactor shift_factor_;
  ConversionFactor stretch_factor_;

  QPoint shift_position_;

  int stretch_width_ = 0;
  int stretch_height_ = 0;
};

#endif  // WIDGET_TRANSFORMER_H
