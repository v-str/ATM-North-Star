#ifndef OPERATION_FRAME_H
#define OPERATION_FRAME_H

#include <QObject>
#include <QRect>

class FrameAnimator;
class QWidget;

class OperationFrame {
  Q_OBJECT
 public:
  explicit OperationFrame(QWidget* widget = nullptr);
  virtual ~OperationFrame();

  void SetAnimationDirection(unsigned int hide_to, unsigned int extrude_from);

 public slots:
  void HideFrame(const QRect& geometry);
  void ExtrudeFrame(const QRect& geometry);

 signals:
  void PassParametersForHide(const QRect& geometry);
  void PassParametersForExtrude(const QRect& geometry);

 private:
  FrameAnimator* hide_animator_ = nullptr;
  FrameAnimator* extrude_animator_ = nullptr;
};

#endif  // OPERATION_FRAME_H
