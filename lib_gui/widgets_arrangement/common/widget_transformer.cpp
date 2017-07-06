#include <widget_transformer.h>

#include <QRect>
#include <QWidget>

#include <side.h>

void WidgetTransformer::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void WidgetTransformer::ShiftWidget(const ConversionFactor& shift_factor,
                                    const QRect& initial_position,
                                    unsigned int manipulation_side,
                                    QWidget* widget) {
  shift_factor_ = shift_factor;
  ComputeShifting(initial_position, manipulation_side);
  widget->move(shift_position_);
}

void WidgetTransformer::StretchWidget(const ConversionFactor& stretch_factor,
                                      const QRect& initial_geometry,
                                      unsigned int manipulation_side,
                                      QWidget* widget) {
  stretch_factor_ = stretch_factor;
  ComputeStretching(initial_geometry, manipulation_side);
  widget->setGeometry(stretch_position_);
}

void WidgetTransformer::ComputeShifting(const QRect& initial_position,
                                        unsigned int manipulation_flag) {
  int x = initial_position.x();
  int y = initial_position.y();

  if (manipulation_flag & Side::kLeft) {
    x -= (shift_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (manipulation_flag & Side::kRight) {
    x += (shift_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (manipulation_flag & Side::kUp) {
    y -= (shift_factor_.YAxisFactor() * delta_size_.Height());
  }
  if (manipulation_flag & Side::kDown) {
    y += (shift_factor_.YAxisFactor() * delta_size_.Height());
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
    width += (stretch_factor_.XAxisFactor() * delta_size_.Width());
    x -= (stretch_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (manipulation_flag & Side::kRight) {
    width += (stretch_factor_.XAxisFactor() * delta_size_.Width());
  }
  if (manipulation_flag & Side::kDown) {
    height += (stretch_factor_.YAxisFactor() * delta_size_.Height());
  }
  if (manipulation_flag & Side::kUp) {
    height += (stretch_factor_.YAxisFactor() * delta_size_.Height());
    y -= (stretch_factor_.YAxisFactor() * delta_size_.Height());
  }

  stretch_position_.setX(x);
  stretch_position_.setY(y);
  stretch_position_.setWidth(width);
  stretch_position_.setHeight(height);
}
