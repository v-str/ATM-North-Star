#ifndef ABSTRACT_FRAME_ANIMATION_H
#define ABSTRACT_FRAME_ANIMATION_H

#include <QObject>

class QWidget;

class AbstractFrameAnimation : public QObject {
  Q_OBJECT
 public:
  explicit AbstractFrameAnimation(QWidget* parent = nullptr);

 signals:

 public slots:
};

#endif  // ABSTRACT_FRAME_ANIMATION_H
