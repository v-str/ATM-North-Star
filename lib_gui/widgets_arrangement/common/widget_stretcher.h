#ifndef WIDGET_STRETCHER_H
#define WIDGET_STRETCHER_H

#include <QPoint>

#include <conversion_factor.h>
#include <delta_size.h>

class QWidget;

class WidgetStretcher {
 public:
  enum StretchDirection {
    kStretchLeft = 1,
    kStretchRight = 2,
    kStretchUp = 4,
    kStretchDown = 8
  };

  void SetDeltaSize(const DeltaSize& delta_size);

  void StretchWidget(const ConversionFactor& conversion_factor,
                     unsigned int direction_flag,
                     const QPoint& initial_size,
                     QWidget* widget);

 private:
  void ComputeStretching(const QPoint& initial_size,
                         unsigned int direction_flag);

  DeltaSize delta_size_;
  ConversionFactor conversion_factor_;
  QPoint widget_size_;
};

#endif  // WIDGET_STRETCHER_H
