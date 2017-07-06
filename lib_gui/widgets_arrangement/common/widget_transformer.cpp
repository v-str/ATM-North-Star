#include <widget_transformer.h>

#include <QRect>
#include <QWidget>

#include <side.h>

void WidgetTransformer::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void WidgetTransformer::Transform(const ConversionFactor& conversion_factor,
                                  const QRect& initial_position,
                                  TransformationType type,
                                  unsigned int manipulation_flag,
                                  QWidget* widget) {
  conversion_factor_ = conversion_factor;
  switch (type) {
    case kShift:
      ComputeShifting(initial_position, manipulation_flag);
      widget->move(shift_position_);
      break;
    case kStretch:
      ComputeStretching(initial_position, manipulation_flag);
      widget->setGeometry(stretch_position_);
      break;
  }
}

void WidgetTransformer::ComputeShifting(const QRect& initial_position,
                                        unsigned int manipulation_flag) {
  int x = initial_position.x();
  int y = initial_position.y();

  if (manipulation_flag & Side::kLeft) {
    x -= (conversion_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (manipulation_flag & Side::kRight) {
    x += (conversion_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (manipulation_flag & Side::kUp) {
    y -= (conversion_factor_.YAxisFactor() * delta_size_.Height());
  }
  if (manipulation_flag & Side::kDown) {
    y += (conversion_factor_.YAxisFactor() * delta_size_.Height());
  }

  shift_position_.setX(x);
  shift_position_.setY(y);
}

void WidgetTransformer::ComputeStretching(const QRect& initial_position,
                                          unsigned int manipulation_flag) {
  int x = initial_position.x();
  int y = initial_position.y();
  int width = initial_position.width();
  int height = initial_position.height();

  if (manipulation_flag & Side::kLeft) {
    width += (conversion_factor_.XAxisFactor() * delta_size_.Width());
    x -= (conversion_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (manipulation_flag & Side::kRight) {
    width += (conversion_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (manipulation_flag & Side::kDown) {
    height += (conversion_factor_.YAxisFactor() * delta_size_.Height());
  }
  if (manipulation_flag & Side::kUp) {
    height += (conversion_factor_.YAxisFactor() * delta_size_.Height());
    y -= (conversion_factor_.YAxisFactor() * delta_size_.Height());
  }

  stretch_position_.setX(x);
  stretch_position_.setY(y);
  stretch_position_.setWidth(width);
  stretch_position_.setHeight(height);
}
