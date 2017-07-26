#ifndef ABSTRACT_FRAME_ANIMATION_H
#define ABSTRACT_FRAME_ANIMATION_H

#include <QObject>

class QPropertyAnimation;
class QWidget;

class AbstractFrameAnimation : public QObject {
  Q_OBJECT
 public:
  explicit AbstractFrameAnimation(QWidget* parent = nullptr);
  ~AbstractFrameAnimation();

 signals:

 public slots:

 private:
  QPropertyAnimation* property_animation_ = nullptr;
};

#endif  // ABSTRACT_FRAME_ANIMATION_H
