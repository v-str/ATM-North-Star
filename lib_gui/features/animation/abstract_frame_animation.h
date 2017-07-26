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

  void SetWidgetForAnimation(QWidget* widget);

 public slots:

 signals:

 protected:
  int CheckOnPositiveValue(int value);

  QPropertyAnimation* PropertyAnimation() const;

 private:
  QPropertyAnimation* property_animation_ = nullptr;

  int animation_direction_ = 4;
  int animation_duration_msec_ = 500;
};

#endif  // ABSTRACT_FRAME_ANIMATION_H
