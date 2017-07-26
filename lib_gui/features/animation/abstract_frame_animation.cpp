#include <abstract_frame_animation.h>

#include <QPropertyAnimation>
#include <QWidget>

AbstractFrameAnimation::AbstractFrameAnimation(QWidget* parent)
    : QObject(parent), property_animation_(new QPropertyAnimation) {}

AbstractFrameAnimation::~AbstractFrameAnimation() {
  delete property_animation_;
}
