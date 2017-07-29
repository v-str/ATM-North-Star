#ifndef OPERATION_FRAME_H
#define OPERATION_FRAME_H

#include <QObject>

class FrameAnimator;
class QWidget;

class OperationFrame {
  Q_OBJECT
 public:
  explicit OperationFrame(QWidget* widget = nullptr);
  virtual ~OperationFrame();

 private:
  FrameAnimator* hide_animator_ = nullptr;
  FrameAnimator* extrude_animator_ = nullptr;
};

#endif  // OPERATION_FRAME_H
